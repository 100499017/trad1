/*
    208, Alberto Socorro Gallardo, Luis Estrada Tallón
    100499017@alumnos.uc3m.es, 100499101@alumnos.uc3m.es
*/

%{                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *my_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;
void add_local_var(char *name) ;
int is_local_var(char *name) ;
char *get_var_name(char *name) ;

char temp [2048] ;
char *nombre_funcion ;

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr

%}

// Definitions for explicit attributes

%token NUMBER        
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token MAIN          // identifica el comienzo del proc. main
%token WHILE         // identifica el bucle while
%token FOR           // Identifica el bucle for
%token IF            // Identifica el if
%token ELSE          // Identifica el else
%token SWITCH        // Identifica la estructura switch
%token CASE          // Identifica los casos
%token DEFAULT       // Identifica el caso por defecto
%token BREAK         // Identifica la sentencia break
%token PUTS          // Identifica la función puts para imprimir cadenas
%token PRINTF        // Identifica la función printf
%token INC           // Identifica función de incremento
%token DEC           // Identifica función de decremento
%token AND OR EQ NEQ LEQ GEQ
%token RETURN



%right '='                    // es la ultima operacion que se debe realizar
%left OR                      // Operador ||
%left AND                     // Operador &&
%left EQ NEQ                  // Operadores ==, !=
%left '<' '>' LEQ GEQ         // Operadores <, >, <=, >=
%left '+' '-'                 // menor orden de precedencia
%left '*' '/' '%'             // orden de precedencia intermedio
%right '!' UNARY_SIGN         // Operador not y de signo

%%                            // Seccion 3 Gramatica - Semantico

axioma:         programa                    { printf ("%s\n", $1.code) ; }
            ;

// Estructura principal: Variables globales (opcionales), funciones (opcionales), función main (obligatoria)
programa:       declaraciones_opt funciones_opt funcion_main  {
                                              sprintf (temp, "%s\n%s\n%s", $1.code, $2.code, $3.code) ;
                                              $$.code = gen_code (temp) ;
                                            }
            ;

/******************** DECLARACIONES DE VARIABLES GLOBALES ********************/

// Declaraciones de variables globales (opcional)
declaraciones_opt:  /* vacio */                         { $$.code = gen_code ("") ; }
            |   declaracion declaraciones_opt           { sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                                          $$.code = gen_code (temp) ; }
            ;

// Pueden declararse en una misma línea una o varias variables (separadas por coma)
declaracion:    INTEGER lista_vars ';'      { $$ = $2 ; }
            |   declaracion_vector          { $$ = $1 ; }
            ;

lista_vars:     var_decl                    { $$.code = gen_code ($1.code) ; }
            |   var_decl ',' lista_vars     { sprintf (temp, "%s %s", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            ;

var_decl:       IDENTIF                     { sprintf (temp, "(setq %s 0)", $1.code) ;
                                              $$.code = gen_code (temp) ; }
            |   IDENTIF '=' NUMBER          { sprintf (temp, "(setq %s %d)", $1.code, $3.value) ;
                                              $$.code = gen_code (temp) ; }
            ;

declaracion_vector:     INTEGER IDENTIF '[' NUMBER ']' ';' {
                                              sprintf (temp, "(setq %s (make-array %d))", $2.code, $4.value) ;
                                              $$.code = gen_code (temp) ;
                                            }
            ;

/******************** FUNCIONES GENÉRICAS ********************/

funciones_opt:  /* vacio */                 { $$.code = gen_code("") ; }
            |   funcion funciones_opt       { sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                              $$.code = gen_code (temp) ; }
            ;

funcion:        IDENTIF                     {nombre_funcion = gen_code ($1.code) ; }
                '(' lista_parametros_opt ')' '{' declaraciones_locales_opt sentencias '}' {
                                              if (strlen($7.code) == 0) {
                                                  sprintf (temp, "(defun %s (%s)\n%s\n)", $1.code, $4.code, $8.code) ;
                                              } else {
                                                  sprintf (temp, "(defun %s (%s)\n%s\n%s\n)", $1.code, $4.code, $7.code, $8.code) ;
                                              }
                                              $$.code = gen_code (temp) ; }
            ;

lista_parametros_opt:   /* vacio */                         { $$.code = gen_code ("") ; }
            |           lista_parametros                    { $$.code = gen_code ($1.code) ; }
            ;

lista_parametros:       parametro                             { $$.code = gen_code ($1.code) ; }
            |           parametro ',' lista_parametros    { sprintf(temp, "%s %s", $1.code, $3.code) ;
                                                            $$.code = gen_code (temp) ; }
            ;

parametro:              INTEGER IDENTIF    { $$.code = gen_code ($2.code) ; }
            ;

// Declaraciones de variables locales en una función (opcional)
declaraciones_locales_opt: /* vacío */      { $$.code = gen_code("") ; }
                    |   declaracion_local declaraciones_locales_opt {
                                              if (strlen($2.code) == 0) {
                                                  $$.code = gen_code($1.code) ;
                                              } else {
                                                  sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                                  $$.code = gen_code (temp) ;
                                              } }
                    ;

declaracion_local: INTEGER IDENTIF ';'      { add_local_var($2.code) ;
                                              sprintf (temp, "(setq %s_%s 0)", nombre_funcion, $2.code) ;
                                              $$.code = gen_code (temp) ; }
            |   INTEGER IDENTIF '=' expresion ';' {
                                              add_local_var($2.code) ;
                                              sprintf (temp, "(setq %s_%s %s)", nombre_funcion, $2.code, $4.code) ;
                                              $$.code = gen_code (temp) ; }
            |   INTEGER IDENTIF '[' NUMBER ']' ';' { add_local_var($2.code) ;
                                              sprintf (temp, "(setq %s_%s (make-array %d))", nombre_funcion, $2.code, $4.value) ;
                                              $$.code = gen_code (temp) ;
                                            }  
            ;

/******************** FUNCIÓN MAIN ********************/

funcion_main:   MAIN                        { nombre_funcion = gen_code ($1.code) ; }
                '(' ')' '{' declaraciones_locales_opt sentencias '}' {
                                              if (strlen($6.code) == 0) {
                                                  sprintf (temp, "(defun main ()\n%s\n)", $7.code) ;
                                              } else {
                                                  sprintf (temp, "(defun main ()\n%s\n%s\n)", $6.code, $7.code) ;
                                              }
                                              $$.code = gen_code (temp) ;
                                            }
            ;

/******************** SENTENCIAS Y EXPRESIONES ********************/

sentencias:     /* vacio */                 { $$.code = gen_code ("") ; }
            |   sentencia sentencias        { sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                              $$.code = gen_code (temp) ; }
            ;

sentencia:      IDENTIF '=' expresion ';'   { sprintf (temp, "(setf %s %s)", get_var_name($1.code), $3.code) ; 
                                              $$.code = gen_code (temp) ; }
            |   PUTS '(' STRING ')' ';'     { sprintf (temp, "(print \"%s\")", $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   PRINTF '(' STRING ',' elem_printf ')' ';' {
                                              sprintf (temp, "(princ %s)", $5.code) ;
                                              $$.code = gen_code (temp) ;
                                            }
            |   PRINTF '(' STRING ',' elem_printf ',' lista_elems_printf ')' ';' {
                                              sprintf (temp, "(progn (princ %s)\n%s)", $5.code, $7.code) ;
                                              $$.code = gen_code (temp) ;
                                            }
            |   WHILE '(' expresion ')' '{' sentencias '}' {
                                              sprintf (temp, "(loop while %s do\n%s)", $3.code, $6.code) ;
                                              $$.code = gen_code (temp) ;
                                            }
            |   IF '(' expresion ')' '{' bloque_condicional '}' {
                                              sprintf (temp, "(if %s\n%s\n)", $3.code, $6.code) ;
                                              $$.code = gen_code (temp) ;
                                            }
            |   IF '(' expresion ')' '{' bloque_condicional '}' ELSE '{' bloque_condicional '}' {
                                              sprintf (temp, "(if %s\n%s\n%s\n)", $3.code, $6.code, $10.code) ;
                                              $$.code = gen_code (temp) ;
                                            }
            |   FOR '(' IDENTIF '=' expresion ';' expresion ';' operacion_inc_dec ')' '{' sentencias '}' {
                                              sprintf (temp, "(setf %s %s)\n(loop while %s do\n%s\n%s)", get_var_name($3.code), $5.code, $7.code, $12.code, $9.code) ;
                                              $$.code = gen_code (temp) ;
                                            }
            |   SWITCH '(' IDENTIF ')' '{' casos default_opt '}' {
                                              if (strlen($7.code) == 0) {
                                                  sprintf (temp, "(case %s\n%s)", get_var_name($3.code), $6.code) ;
                                              } else {
                                                  sprintf (temp, "(case %s\n%s\n%s)", get_var_name($3.code), $6.code, $7.code) ;
                                              }
                                              $$.code = gen_code (temp) ;
                                            }
            |   IDENTIF '(' lista_argumentos_opt ')' ';'    {
                                              sprintf (temp, "(%s %s)", $1.code, $3.code) ; 
                                              $$.code = gen_code (temp) ;
                                            }
            |   RETURN expresion ';'        { sprintf(temp, "(return-from %s %s)", nombre_funcion, $2.code);
                                            $$.code = gen_code(temp); } // caso 2 return no al final
            |   IDENTIF '[' expresion ']' '=' expresion ';' { 
                                              sprintf (temp, "(setf (aref %s %s) %s)", get_var_name($1.code), $3.code, $6.code) ; 
                                              $$.code = gen_code (temp) ;
                                            }
            ;

expresion:      termino                     { $$ = $1 ; }
            |   expresion '+' expresion     { sprintf (temp, "(+ %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion '-' expresion     { sprintf (temp, "(- %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion '*' expresion     { sprintf (temp, "(* %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion '/' expresion     { sprintf (temp, "(/ %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion '%' expresion     { sprintf (temp, "(mod %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion OR expresion      { sprintf (temp, "(or %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion AND expresion     { sprintf (temp, "(and %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion EQ expresion      { sprintf (temp, "(= %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion NEQ expresion     { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion '<' expresion     { sprintf (temp, "(< %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion LEQ expresion     { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion '>' expresion     { sprintf (temp, "(> %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   expresion GEQ expresion     { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            |   '!' expresion               { sprintf (temp, "(not %s)", $2.code) ;
                                              $$.code = gen_code (temp) ; }
            ;

termino:        operando                    { $$ = $1 ; }                          
            |   '+' operando %prec UNARY_SIGN   { $$ = $1 ; }
            |   '-' operando %prec UNARY_SIGN   { sprintf (temp, "(- %s)", $2.code) ;
                                                  $$.code = gen_code (temp) ; }    
            ;

operando:       IDENTIF                     { sprintf (temp, "%s", get_var_name($1.code)) ;
                                              $$.code = gen_code (temp) ; }
            |   NUMBER                      { sprintf (temp, "%d", $1.value) ;
                                              $$.code = gen_code (temp) ; }
            |   '(' expresion ')'           { $$.code = gen_code ($2.code) ; }
            |   IDENTIF '(' lista_argumentos_opt ')'    { sprintf (temp, "(%s %s)", $1.code, $3.code) ; 
                                                        $$.code = gen_code (temp) ; }
            |   IDENTIF '[' expresion ']'   { sprintf (temp, "(aref %s %s)", get_var_name($1.code), $3.code) ; 
                                            $$.code = gen_code (temp) ; } 
            ;

elem_printf:    expresion                   { $$ = $1 ; }
            |   STRING                      { sprintf (temp, "\"%s\"", $1.code) ;
                                              $$.code = gen_code (temp) ; }
            ;

lista_elems_printf: elem_printf             { sprintf (temp, "(princ %s)", $1.code) ;
                                              $$.code = gen_code (temp); }
            |   elem_printf ',' lista_elems_printf  {
                                              sprintf (temp, "(princ %s) %s", $1.code, $3.code) ;
                                              $$.code = gen_code (temp) ; }
            ;

// El bloque condicional decide: 1 sentencia o varias (con progn)
bloque_condicional:     sentencia           { $$ = $1 ; }
                    |   lista_varias_sentencias {
                                              sprintf (temp, "(progn %s)", $1.code) ;
                                              $$.code = gen_code (temp) ; }
                    ;

// Regla para capturar 2 o más sentencias
lista_varias_sentencias:    sentencia sentencia {
                                              sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                              $$.code = gen_code (temp) ; }
                        |   sentencia lista_varias_sentencias {
                                              sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                              $$.code = gen_code (temp) ; }
                        ;

// Regla para las operaciones de incremento y decremento del for
operacion_inc_dec:  INC '(' IDENTIF ')'     { sprintf (temp, "(setf %s (+ %s 1))", get_var_name($3.code), get_var_name($3.code)) ;
                                              $$.code = gen_code (temp) ; }
            |       DEC '(' IDENTIF ')'     { sprintf (temp, "(setf %s (- %s 1))", get_var_name($3.code), get_var_name($3.code)) ;
                                              $$.code = gen_code (temp) ; }
            ;

// Reglas para los casos del switch
casos:          caso                        { $$.code = gen_code ($1.code) ; }
            |   caso casos                  { sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                              $$.code = gen_code (temp) ; }
            ;

// Cada caso tiene su propio break;
caso:           CASE NUMBER ':' sentencias BREAK ';' {
                                              sprintf (temp, "(%d\n%s)", $2.value, $4.code) ;
                                              $$.code = gen_code (temp) ;
                                            }
            ;

// El default es opcional
default_opt:    /* vacío */                 { $$.code = gen_code ("") ; }
            |   DEFAULT ':' sentencias BREAK ';'    { sprintf (temp, "(otherwise\n%s)", $3.code) ;
                                                      $$.code = gen_code (temp) ; }
            ;

// Argumentos al llamar a una función

lista_argumentos_opt:   /* vacio */                         { $$.code = gen_code ("") ; }
            |           lista_argumentos                    { $$.code = gen_code ($1.code) ; }
            ;

lista_argumentos:       expresion                           { $$.code = gen_code ($1.code) ; }
            |           expresion ',' lista_argumentos          { sprintf (temp, "%s %s", $1.code, $3.code) ; 
                                                            $$.code = gen_code (temp) ; }
            ;

%%                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%d", n) ;

    return gen_code (ltemp) ;
}

char *char_to_string (char c)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%c", c) ;

    return gen_code (ltemp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}

char local_vars[100][256];
int num_local_vars = 0;

void add_local_var(char *name) {
    if (num_local_vars < 100) {
        strcpy(local_vars[num_local_vars], name);
        num_local_vars++;
    }
}

int is_local_var(char *name) {
    for (int i = 0; i < num_local_vars; i++) {
        if (strcmp(local_vars[i], name) == 0) {
            return 1; // Verdadero: es local
        }
    }
    return 0; // Falso: es global
}

// Esta función devuelve "main_x" si es local, o "x" si es global
char *get_var_name(char *name) {
    if (is_local_var(name)) {
        char temp_name[512];
        sprintf(temp_name, "%s_%s", nombre_funcion, name);    // modificado para que si es local no tenga el nombre main_, sino que el nombre real de la función
        return gen_code(temp_name);
    }
    return name;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "puts",        PUTS,           // Añadido para reconocer la función de impresión
    "printf",      PRINTF,         // Añadido para reconocer printf
    "while",       WHILE,          // Añadido para reconocer el bucle while
    "for",         FOR,            // Añadido para reconocer el bucle for
    "if",          IF,             // Añadido para reconocer condicional if
    "else",        ELSE,           // Añadido para reconocer el condicional else
    "switch",      SWITCH,         // Añadido para switch
    "case",        CASE,           // Añadido para case
    "default",     DEFAULT,        // Añadido para default
    "break",       BREAK,          // Añadido para break
    "inc",         INC,            // Añadido para reconocer el incremento
    "dec",         DEC,            // Añadido para reconocer el decremento
    "&&",          AND,            // Añadido para reconocer &&
    "||",          OR,             // Añadido para reconocer ||
    "==",          EQ,             // Añadido para reconocer ==
    "!=",          NEQ,            // Añadido para reconocer !=
    "<=",          LEQ,            // Añadido para reconocer <=
    ">=",          GEQ,            // Añadido para reconocer >=
    "return",       RETURN,         // Añadido para reconocer el return
    NULL,          0               // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
