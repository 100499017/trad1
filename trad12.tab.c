/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "trad12.y"
                          // SECCION 1 Declaraciones de C-Yacc

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


#line 117 "trad12.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "trad12.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_SWITCH = 12,                    /* SWITCH  */
  YYSYMBOL_CASE = 13,                      /* CASE  */
  YYSYMBOL_DEFAULT = 14,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 15,                     /* BREAK  */
  YYSYMBOL_PUTS = 16,                      /* PUTS  */
  YYSYMBOL_PRINTF = 17,                    /* PRINTF  */
  YYSYMBOL_INC = 18,                       /* INC  */
  YYSYMBOL_DEC = 19,                       /* DEC  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_LEQ = 24,                       /* LEQ  */
  YYSYMBOL_GEQ = 25,                       /* GEQ  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_35_ = 35,                       /* '!'  */
  YYSYMBOL_UNARY_SIGN = 36,                /* UNARY_SIGN  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_axioma = 47,                    /* axioma  */
  YYSYMBOL_programa = 48,                  /* programa  */
  YYSYMBOL_tipo = 49,                      /* tipo  */
  YYSYMBOL_declaraciones_opt = 50,         /* declaraciones_opt  */
  YYSYMBOL_declaracion = 51,               /* declaracion  */
  YYSYMBOL_declaracion_vector = 52,        /* declaracion_vector  */
  YYSYMBOL_lista_vars = 53,                /* lista_vars  */
  YYSYMBOL_var_decl = 54,                  /* var_decl  */
  YYSYMBOL_declaraciones_locales_opt = 55, /* declaraciones_locales_opt  */
  YYSYMBOL_declarar_local = 56,            /* declarar_local  */
  YYSYMBOL_funciones_opt = 57,             /* funciones_opt  */
  YYSYMBOL_funcion = 58,                   /* funcion  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_lista_parametros_opt = 60,      /* lista_parametros_opt  */
  YYSYMBOL_parametro = 61,                 /* parametro  */
  YYSYMBOL_lista_argumentos_opt = 62,      /* lista_argumentos_opt  */
  YYSYMBOL_funcion_main = 63,              /* funcion_main  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_sentencias = 65,                /* sentencias  */
  YYSYMBOL_operacion_inc_dec = 66,         /* operacion_inc_dec  */
  YYSYMBOL_casos = 67,                     /* casos  */
  YYSYMBOL_caso = 68,                      /* caso  */
  YYSYMBOL_default_opt = 69,               /* default_opt  */
  YYSYMBOL_sentencia = 70,                 /* sentencia  */
  YYSYMBOL_lista_varias_sentencias = 71,   /* lista_varias_sentencias  */
  YYSYMBOL_bloque_condicional = 72,        /* bloque_condicional  */
  YYSYMBOL_lista_elems_printf = 73,        /* lista_elems_printf  */
  YYSYMBOL_elem_printf = 74,               /* elem_printf  */
  YYSYMBOL_expresion = 75,                 /* expresion  */
  YYSYMBOL_termino = 76,                   /* termino  */
  YYSYMBOL_operando = 77                   /* operando  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   436

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,     2,     2,    34,     2,     2,
      41,    42,    32,    30,    40,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    37,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    91,    96,   100,   101,   103,   108,   111,
     115,   116,   120,   122,   127,   128,   137,   140,   144,   148,
     149,   153,   153,   162,   163,   164,   168,   171,   172,   173,
     177,   177,   186,   187,   192,   194,   199,   200,   205,   211,
     212,   217,   219,   221,   222,   225,   228,   231,   234,   241,
     244,   247,   252,   255,   261,   262,   267,   269,   274,   275,
     279,   280,   282,   284,   286,   288,   290,   292,   294,   296,
     298,   300,   302,   304,   306,   310,   311,   312,   316,   318,
     320,   321,   323
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "FOR", "IF", "ELSE", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "PUTS", "PRINTF", "INC", "DEC", "AND", "OR",
  "EQ", "NEQ", "LEQ", "GEQ", "RETURN", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "UNARY_SIGN", "';'", "'['", "']'", "','",
  "'('", "')'", "'{'", "'}'", "':'", "$accept", "axioma", "programa",
  "tipo", "declaraciones_opt", "declaracion", "declaracion_vector",
  "lista_vars", "var_decl", "declaraciones_locales_opt", "declarar_local",
  "funciones_opt", "funcion", "$@1", "lista_parametros_opt", "parametro",
  "lista_argumentos_opt", "funcion_main", "$@2", "sentencias",
  "operacion_inc_dec", "casos", "caso", "default_opt", "sentencia",
  "lista_varias_sentencias", "bloque_condicional", "lista_elems_printf",
  "elem_printf", "expresion", "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -128,    10,  -128,    21,  -128,  -128,    16,  -128,  -128,     8,
     -20,    -7,  -128,  -128,  -128,  -128,  -128,    75,    79,  -128,
      70,    48,    52,  -128,    46,    90,  -128,    21,    59,    76,
     118,    -6,  -128,    91,  -128,  -128,    21,    98,  -128,  -128,
    -128,    21,    21,   127,  -128,  -128,    15,    60,    83,   -24,
     101,   103,   110,   150,   151,   152,    88,  -128,  -128,  -128,
      88,  -128,    88,    88,    88,    88,   162,    88,   177,   193,
     194,  -128,    -3,     1,     1,    88,    88,   255,  -128,  -128,
     273,   291,   215,    31,   363,   125,   179,   140,   165,   166,
     164,    88,    88,  -128,  -128,  -128,   155,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
    -128,  -128,  -128,   187,    88,   178,   176,    88,   180,   188,
     184,   102,   235,    69,  -128,   391,   378,   402,   402,    94,
      94,    94,    94,   106,   106,  -128,  -128,  -128,    88,   363,
    -128,  -128,   309,   216,   209,  -128,  -128,    74,  -128,   363,
    -128,  -128,   327,    71,    88,   216,   216,   185,   227,    44,
    -128,   102,   197,  -128,  -128,   345,  -128,  -128,   230,   205,
     206,  -128,   208,  -128,  -128,    43,   210,  -128,  -128,  -128,
     220,   221,   228,   216,   186,   201,   267,   268,   238,   229,
     245,   253,   249,   257,  -128,  -128,  -128,  -128,  -128,  -128,
      86,  -128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,    19,     1,     4,     0,     6,     7,     0,
      12,     0,    10,    21,    30,    20,     3,     0,     0,     8,
       0,     0,     0,    13,     0,    12,    11,    23,     0,     0,
       0,     0,    24,     0,     9,    26,     0,     0,    14,    25,
      14,    32,    32,     0,    18,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    33,    22,
       0,    16,     0,     0,    27,     0,     0,     0,     0,     0,
       0,    79,    78,     0,     0,     0,     0,     0,    60,    75,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,     0,    27,    76,    77,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    17,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    67,    66,    68,    69,    71,
      73,    70,    72,    61,    62,    63,    64,    65,     0,    29,
      49,    32,     0,     0,     0,    42,    59,     0,    56,    58,
      82,    81,     0,     0,     0,    54,    55,     0,     0,    39,
      36,     0,     0,    51,    44,     0,    52,    53,    45,     0,
       0,    37,     0,    57,    43,     0,     0,    32,    32,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    46,    38,    40,    34,    35,
       0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,    -2,  -128,  -128,   297,  -128,   288,   269,
    -128,  -128,  -128,  -128,  -128,   281,   226,  -128,  -128,   -42,
    -128,  -128,   167,  -128,  -127,  -128,   144,  -128,   174,   -54,
    -128,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    30,     3,     7,    44,    11,    12,    41,
      45,     9,    15,    21,    31,    32,    83,    16,    22,    46,
     182,   159,   160,   172,    58,   156,   157,   147,   148,    84,
      78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,     6,    77,    62,    71,    72,    80,    17,    81,    82,
       4,    85,    13,    87,    63,    14,   155,    64,    18,    49,
      10,    95,    96,    50,    51,    52,     5,    53,   166,   167,
      19,    54,    55,    20,    36,    91,    37,   122,    92,    43,
      43,    56,    76,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   155,   158,   170,    57,
     139,   180,   181,   142,    49,    93,    94,   149,    50,    51,
      52,   114,    53,   115,    25,    49,    54,    55,    23,    50,
      51,    52,    24,    53,   152,    29,    56,    54,    55,    27,
      49,    71,    72,    28,    50,    51,    52,    56,    53,   153,
     165,    33,    54,    55,    59,    71,    72,   149,   146,   114,
      60,   151,    56,    34,   161,   164,   162,    17,    73,    74,
      61,    18,    35,    75,   105,   106,   107,   108,   109,    76,
     201,    48,    73,    74,    38,   184,   185,    75,   107,   108,
     109,    40,    65,    76,    66,    97,    98,    99,   100,   101,
     102,    67,   200,   103,   104,   105,   106,   107,   108,   109,
      97,    98,    99,   100,   101,   102,    86,   116,   103,   104,
     105,   106,   107,   108,   109,    97,    98,    99,   100,   101,
     102,    88,   118,   103,   104,   105,   106,   107,   108,   109,
      49,    68,    69,    70,    50,    51,    52,   124,    53,    89,
      90,   190,    54,    55,   121,    49,   117,   119,   120,    50,
      51,    52,    56,    53,   138,   140,   191,    54,    55,   141,
      49,   145,   158,   143,    50,    51,    52,    56,    53,   168,
     169,   144,    54,    55,   174,    97,    98,    99,   100,   101,
     102,   176,    56,   103,   104,   105,   106,   107,   108,   109,
     177,   178,   179,   183,   113,    97,    98,    99,   100,   101,
     102,   186,   187,   103,   104,   105,   106,   107,   108,   109,
     188,   192,   193,   195,   150,    97,    98,    99,   100,   101,
     102,   194,   196,   103,   104,   105,   106,   107,   108,   109,
     197,   198,   110,    97,    98,    99,   100,   101,   102,   199,
       8,   103,   104,   105,   106,   107,   108,   109,    26,    42,
     111,    97,    98,    99,   100,   101,   102,    39,   123,   103,
     104,   105,   106,   107,   108,   109,   171,   189,   112,    97,
      98,    99,   100,   101,   102,   173,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,   154,    97,    98,    99,
     100,   101,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,   163,    97,    98,    99,   100,   101,
     102,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,   175,    97,    98,    99,   100,   101,   102,     0,
       0,   103,   104,   105,   106,   107,   108,   109,    97,     0,
      99,   100,   101,   102,     0,     0,   103,   104,   105,   106,
     107,   108,   109,    99,   100,   101,   102,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   101,   102,     0,     0,
     103,   104,   105,   106,   107,   108,   109
};

static const yytype_int16 yycheck[] =
{
      42,     3,    56,    27,     3,     4,    60,    27,    62,    63,
       0,    65,     4,    67,    38,     7,   143,    41,    38,     4,
       4,    75,    76,     8,     9,    10,     5,    12,   155,   156,
      37,    16,    17,    40,    40,    38,    42,    91,    41,    41,
      42,    26,    41,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   183,    13,    14,    44,
     114,    18,    19,   117,     4,    73,    74,   121,     8,     9,
      10,    40,    12,    42,     4,     4,    16,    17,     3,     8,
       9,    10,     3,    12,   138,    39,    26,    16,    17,    41,
       4,     3,     4,    41,     8,     9,    10,    26,    12,   141,
     154,    42,    16,    17,    44,     3,     4,   161,     6,    40,
      27,    42,    26,    37,    40,    44,    42,    27,    30,    31,
      37,    38,     4,    35,    30,    31,    32,    33,    34,    41,
      44,     4,    30,    31,    43,   177,   178,    35,    32,    33,
      34,    43,    41,    41,    41,    20,    21,    22,    23,    24,
      25,    41,   194,    28,    29,    30,    31,    32,    33,    34,
      20,    21,    22,    23,    24,    25,     4,    42,    28,    29,
      30,    31,    32,    33,    34,    20,    21,    22,    23,    24,
      25,     4,    42,    28,    29,    30,    31,    32,    33,    34,
       4,    41,    41,    41,     8,     9,    10,    42,    12,     6,
       6,    15,    16,    17,    40,     4,    27,    42,    42,     8,
       9,    10,    26,    12,    27,    37,    15,    16,    17,    43,
       4,    37,    13,    43,     8,     9,    10,    26,    12,    44,
       3,    43,    16,    17,    37,    20,    21,    22,    23,    24,
      25,    11,    26,    28,    29,    30,    31,    32,    33,    34,
      45,    45,    44,    43,    39,    20,    21,    22,    23,    24,
      25,    41,    41,    28,    29,    30,    31,    32,    33,    34,
      42,     4,     4,    44,    39,    20,    21,    22,    23,    24,
      25,    43,    37,    28,    29,    30,    31,    32,    33,    34,
      37,    42,    37,    20,    21,    22,    23,    24,    25,    42,
       3,    28,    29,    30,    31,    32,    33,    34,    20,    40,
      37,    20,    21,    22,    23,    24,    25,    36,    92,    28,
      29,    30,    31,    32,    33,    34,   159,   183,    37,    20,
      21,    22,    23,    24,    25,   161,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    37,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    37,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    37,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    20,    -1,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    24,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,    50,     0,     5,    49,    51,    52,    57,
       4,    53,    54,     4,     7,    58,    63,    27,    38,    37,
      40,    59,    64,     3,     3,     4,    54,    41,    41,    39,
      49,    60,    61,    42,    37,     4,    40,    42,    43,    61,
      43,    55,    55,    49,    52,    56,    65,    65,     4,     4,
       8,     9,    10,    12,    16,    17,    26,    44,    70,    44,
      27,    37,    27,    38,    41,    41,    41,    41,    41,    41,
      41,     3,     4,    30,    31,    35,    41,    75,    76,    77,
      75,    75,    75,    62,    75,    75,     4,    75,     4,     6,
       6,    38,    41,    77,    77,    75,    75,    20,    21,    22,
      23,    24,    25,    28,    29,    30,    31,    32,    33,    34,
      37,    37,    37,    39,    40,    42,    42,    27,    42,    42,
      42,    40,    75,    62,    42,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    27,    75,
      37,    43,    75,    43,    43,    37,     6,    73,    74,    75,
      39,    42,    75,    65,    37,    70,    71,    72,    13,    67,
      68,    40,    42,    37,    44,    75,    70,    70,    44,     3,
      14,    68,    69,    74,    37,    37,    11,    45,    45,    44,
      18,    19,    66,    43,    65,    65,    41,    41,    42,    72,
      15,    15,     4,     4,    43,    44,    37,    37,    42,    42,
      65,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    49,    50,    50,    50,    51,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      57,    59,    58,    60,    60,    60,    61,    62,    62,    62,
      64,    63,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    77,    77,
      77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     0,     2,     2,     3,     6,
       1,     3,     1,     3,     0,     2,     3,     5,     1,     0,
       2,     0,     9,     0,     1,     3,     2,     0,     1,     3,
       0,     8,     0,     2,     4,     4,     1,     2,     6,     0,
       5,     4,     5,     7,     7,     7,    11,    13,     8,     5,
       3,     7,     2,     2,     1,     1,     1,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     2,     2,     1,     1,
       3,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* axioma: programa  */
#line 87 "trad12.y"
                                            { printf ("%s\n", yyvsp[0].code) ; }
#line 1357 "trad12.tab.c"
    break;

  case 3: /* programa: declaraciones_opt funciones_opt funcion_main  */
#line 91 "trad12.y"
                                                              { sprintf (temp, "%s\n%s\n%s", yyvsp[-2].code, yyvsp[-1].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1364 "trad12.tab.c"
    break;

  case 4: /* tipo: INTEGER  */
#line 96 "trad12.y"
                    { yyval.code = gen_code (yyvsp[0].code); }
#line 1370 "trad12.tab.c"
    break;

  case 5: /* declaraciones_opt: %empty  */
#line 100 "trad12.y"
                                             { yyval.code = gen_code ("") ; }
#line 1376 "trad12.tab.c"
    break;

  case 6: /* declaraciones_opt: declaraciones_opt declaracion  */
#line 101 "trad12.y"
                                                { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1383 "trad12.tab.c"
    break;

  case 7: /* declaraciones_opt: declaraciones_opt declaracion_vector  */
#line 103 "trad12.y"
                                                        { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ; 
                                                        yyval.code = gen_code (temp) ; }
#line 1390 "trad12.tab.c"
    break;

  case 8: /* declaracion: tipo lista_vars ';'  */
#line 108 "trad12.y"
                                         { yyval = yyvsp[-1] ; }
#line 1396 "trad12.tab.c"
    break;

  case 9: /* declaracion_vector: tipo IDENTIF '[' NUMBER ']' ';'  */
#line 111 "trad12.y"
                                                            { sprintf (temp, "(setq %s (make-array %d))", get_var_name(yyvsp[-4].code), yyvsp[-2].value) ;
                                                            yyval.code = gen_code (temp) ; }
#line 1403 "trad12.tab.c"
    break;

  case 10: /* lista_vars: var_decl  */
#line 115 "trad12.y"
                                            { yyval = yyvsp[0] ; }
#line 1409 "trad12.tab.c"
    break;

  case 11: /* lista_vars: lista_vars ',' var_decl  */
#line 116 "trad12.y"
                                            { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1416 "trad12.tab.c"
    break;

  case 12: /* var_decl: IDENTIF  */
#line 120 "trad12.y"
                                            { sprintf (temp, "(setq %s 0)", yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1423 "trad12.tab.c"
    break;

  case 13: /* var_decl: IDENTIF '=' NUMBER  */
#line 122 "trad12.y"
                                            { sprintf (temp, "(setq %s %d)", yyvsp[-2].code, yyvsp[0].value) ;
                                              yyval.code = gen_code (temp) ; }
#line 1430 "trad12.tab.c"
    break;

  case 14: /* declaraciones_locales_opt: %empty  */
#line 127 "trad12.y"
                                                 { yyval.code = gen_code("") ; }
#line 1436 "trad12.tab.c"
    break;

  case 15: /* declaraciones_locales_opt: declaraciones_locales_opt declarar_local  */
#line 128 "trad12.y"
                                                                 {
                                              if (strlen(yyvsp[-1].code) == 0) {
                                                  yyval.code = gen_code(yyvsp[0].code) ;
                                              } else {
                                                  sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                  yyval.code = gen_code (temp) ;
                                              } }
#line 1448 "trad12.tab.c"
    break;

  case 16: /* declarar_local: tipo IDENTIF ';'  */
#line 137 "trad12.y"
                                         { add_local_var(yyvsp[-1].code) ;
                                              sprintf (temp, "(setq %s_%s 0)", nombre_funcion, yyvsp[-1].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1456 "trad12.tab.c"
    break;

  case 17: /* declarar_local: tipo IDENTIF '=' expresion ';'  */
#line 140 "trad12.y"
                                               {
                                              add_local_var(yyvsp[-3].code) ;
                                              sprintf (temp, "(setq %s_%s %s)", nombre_funcion, yyvsp[-3].code, yyvsp[-1].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1465 "trad12.tab.c"
    break;

  case 18: /* declarar_local: declaracion_vector  */
#line 144 "trad12.y"
                                        { yyval.code = gen_code (yyvsp[0].code) ; }
#line 1471 "trad12.tab.c"
    break;

  case 19: /* funciones_opt: %empty  */
#line 148 "trad12.y"
                                           { yyval.code = gen_code("") ; }
#line 1477 "trad12.tab.c"
    break;

  case 20: /* funciones_opt: funciones_opt funcion  */
#line 149 "trad12.y"
                                            { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1484 "trad12.tab.c"
    break;

  case 21: /* $@1: %empty  */
#line 153 "trad12.y"
                        {nombre_funcion = gen_code (yyvsp[0].code) ; }
#line 1490 "trad12.tab.c"
    break;

  case 22: /* funcion: IDENTIF $@1 '(' lista_parametros_opt ')' '{' declaraciones_locales_opt sentencias '}'  */
#line 153 "trad12.y"
                                                                                                                                              {
                                              if (strlen(yyvsp[-2].code) == 0) {
                                                  sprintf (temp, "(defun %s (%s)\n%s\n)", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code) ;
                                              } else {
                                                  sprintf (temp, "(defun %s (%s)\n%s\n%s\n)", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-2].code, yyvsp[-1].code) ;
                                              }
                                              yyval.code = gen_code (temp) ; }
#line 1502 "trad12.tab.c"
    break;

  case 23: /* lista_parametros_opt: %empty  */
#line 162 "trad12.y"
                                                            { yyval.code = gen_code ("") ; }
#line 1508 "trad12.tab.c"
    break;

  case 24: /* lista_parametros_opt: parametro  */
#line 163 "trad12.y"
                                                              { yyval.code = gen_code (yyvsp[0].code) ; }
#line 1514 "trad12.tab.c"
    break;

  case 25: /* lista_parametros_opt: lista_parametros_opt ',' parametro  */
#line 164 "trad12.y"
                                                              { sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                                            yyval.code = gen_code (temp) ; }
#line 1521 "trad12.tab.c"
    break;

  case 26: /* parametro: tipo IDENTIF  */
#line 168 "trad12.y"
                                        { yyval.code = gen_code (yyvsp[0].code) ; }
#line 1527 "trad12.tab.c"
    break;

  case 27: /* lista_argumentos_opt: %empty  */
#line 171 "trad12.y"
                                                            { yyval.code = gen_code ("") ; }
#line 1533 "trad12.tab.c"
    break;

  case 28: /* lista_argumentos_opt: expresion  */
#line 172 "trad12.y"
                                                 { yyval.code = gen_code (yyvsp[0].code) ; }
#line 1539 "trad12.tab.c"
    break;

  case 29: /* lista_argumentos_opt: lista_argumentos_opt ',' expresion  */
#line 173 "trad12.y"
                                                            { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ; 
                                                            yyval.code = gen_code (temp) ; }
#line 1546 "trad12.tab.c"
    break;

  case 30: /* $@2: %empty  */
#line 177 "trad12.y"
                     {nombre_funcion = gen_code (yyvsp[0].code) ; }
#line 1552 "trad12.tab.c"
    break;

  case 31: /* funcion_main: MAIN $@2 '(' ')' '{' declaraciones_locales_opt sentencias '}'  */
#line 177 "trad12.y"
                                                                                                                   {
                                              if (strlen(yyvsp[-2].code) == 0) {
                                                  sprintf (temp, "(defun main ()\n%s\n)", yyvsp[-1].code) ;
                                              } else {
                                                  sprintf (temp, "(defun main ()\n%s\n%s\n)", yyvsp[-2].code, yyvsp[-1].code) ;
                                              }
                                              yyval.code = gen_code (temp) ; }
#line 1564 "trad12.tab.c"
    break;

  case 32: /* sentencias: %empty  */
#line 186 "trad12.y"
                                              { yyval.code = gen_code ("") ; }
#line 1570 "trad12.tab.c"
    break;

  case 33: /* sentencias: sentencias sentencia  */
#line 187 "trad12.y"
                                            { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1577 "trad12.tab.c"
    break;

  case 34: /* operacion_inc_dec: INC '(' IDENTIF ')'  */
#line 192 "trad12.y"
                                            { sprintf (temp, "(setf %s (+ %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1584 "trad12.tab.c"
    break;

  case 35: /* operacion_inc_dec: DEC '(' IDENTIF ')'  */
#line 194 "trad12.y"
                                            { sprintf (temp, "(setf %s (- %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1591 "trad12.tab.c"
    break;

  case 36: /* casos: caso  */
#line 199 "trad12.y"
                                            { yyval.code = yyvsp[0].code ; }
#line 1597 "trad12.tab.c"
    break;

  case 37: /* casos: casos caso  */
#line 200 "trad12.y"
                                            { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1604 "trad12.tab.c"
    break;

  case 38: /* caso: CASE NUMBER ':' sentencias BREAK ';'  */
#line 205 "trad12.y"
                                                     {
                                              sprintf (temp, "(%d\n%s)", yyvsp[-4].value, yyvsp[-2].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1612 "trad12.tab.c"
    break;

  case 39: /* default_opt: %empty  */
#line 211 "trad12.y"
                                             { yyval.code = gen_code ("") ; }
#line 1618 "trad12.tab.c"
    break;

  case 40: /* default_opt: DEFAULT ':' sentencias BREAK ';'  */
#line 212 "trad12.y"
                                                 {
                                              sprintf (temp, "(otherwise\n%s)", yyvsp[-2].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1626 "trad12.tab.c"
    break;

  case 41: /* sentencia: IDENTIF '=' expresion ';'  */
#line 217 "trad12.y"
                                            { sprintf (temp, "(setf %s %s)", get_var_name(yyvsp[-3].code), yyvsp[-1].code) ; 
                                              yyval.code = gen_code (temp) ; }
#line 1633 "trad12.tab.c"
    break;

  case 42: /* sentencia: PUTS '(' STRING ')' ';'  */
#line 219 "trad12.y"
                                            { sprintf (temp, "(print \"%s\")", yyvsp[-2].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1640 "trad12.tab.c"
    break;

  case 43: /* sentencia: PRINTF '(' STRING ',' lista_elems_printf ')' ';'  */
#line 221 "trad12.y"
                                                                 { yyval = yyvsp[-2] ; }
#line 1646 "trad12.tab.c"
    break;

  case 44: /* sentencia: WHILE '(' expresion ')' '{' sentencias '}'  */
#line 222 "trad12.y"
                                                           {
                                              sprintf (temp, "(loop while %s do\n%s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1654 "trad12.tab.c"
    break;

  case 45: /* sentencia: IF '(' expresion ')' '{' bloque_condicional '}'  */
#line 225 "trad12.y"
                                                                {
                                              sprintf (temp, "(if %s\n%s\n)", yyvsp[-4].code, yyvsp[-1].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1662 "trad12.tab.c"
    break;

  case 46: /* sentencia: IF '(' expresion ')' '{' bloque_condicional '}' ELSE '{' bloque_condicional '}'  */
#line 228 "trad12.y"
                                                                                                {
                                              sprintf (temp, "(if %s\n%s\n%s\n)", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1670 "trad12.tab.c"
    break;

  case 47: /* sentencia: FOR '(' IDENTIF '=' expresion ';' expresion ';' operacion_inc_dec ')' '{' sentencias '}'  */
#line 231 "trad12.y"
                                                                                                         {
                                              sprintf (temp, "(setf %s %s)\n(loop while %s do\n%s\n%s)", get_var_name(yyvsp[-10].code), yyvsp[-8].code, yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1678 "trad12.tab.c"
    break;

  case 48: /* sentencia: SWITCH '(' IDENTIF ')' '{' casos default_opt '}'  */
#line 234 "trad12.y"
                                                                 {
                                              if (strlen(yyvsp[-1].code) == 0) {
                                                  sprintf (temp, "(case %s\n%s)", get_var_name(yyvsp[-5].code), yyvsp[-2].code) ;
                                              } else {
                                                  sprintf (temp, "(case %s\n%s\n%s)", get_var_name(yyvsp[-5].code), yyvsp[-2].code, yyvsp[-1].code) ;
                                              }
                                              yyval.code = gen_code (temp) ; }
#line 1690 "trad12.tab.c"
    break;

  case 49: /* sentencia: IDENTIF '(' lista_argumentos_opt ')' ';'  */
#line 241 "trad12.y"
                                                            { sprintf (temp, "(%s %s)", yyvsp[-4].code, yyvsp[-2].code) ; 
                                                            yyval.code = gen_code (temp) ;
                                                            }
#line 1698 "trad12.tab.c"
    break;

  case 50: /* sentencia: RETURN expresion ';'  */
#line 244 "trad12.y"
                                            { sprintf(temp, "(return-from %s %s)", nombre_funcion, yyvsp[-1].code);
                                            yyval.code = gen_code(temp);
                                            }
#line 1706 "trad12.tab.c"
    break;

  case 51: /* sentencia: IDENTIF '[' expresion ']' '=' expresion ';'  */
#line 247 "trad12.y"
                                                                { sprintf (temp, "(setf (aref %s %s) %s)", get_var_name(yyvsp[-6].code), yyvsp[-4].code, yyvsp[-1].code) ; 
                                                                yyval.code = gen_code (temp) ;}
#line 1713 "trad12.tab.c"
    break;

  case 52: /* lista_varias_sentencias: sentencia sentencia  */
#line 252 "trad12.y"
                                                {
                                              sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1721 "trad12.tab.c"
    break;

  case 53: /* lista_varias_sentencias: lista_varias_sentencias sentencia  */
#line 255 "trad12.y"
                                                              {
                                              sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1729 "trad12.tab.c"
    break;

  case 54: /* bloque_condicional: sentencia  */
#line 261 "trad12.y"
                                            { yyval = yyvsp[0] ; }
#line 1735 "trad12.tab.c"
    break;

  case 55: /* bloque_condicional: lista_varias_sentencias  */
#line 262 "trad12.y"
                                                {
                                              sprintf (temp, "(progn\n%s)", yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1743 "trad12.tab.c"
    break;

  case 56: /* lista_elems_printf: elem_printf  */
#line 267 "trad12.y"
                                            { sprintf (temp, "(princ %s)", yyvsp[0].code) ;
                                              yyval.code = gen_code (temp); }
#line 1750 "trad12.tab.c"
    break;

  case 57: /* lista_elems_printf: lista_elems_printf ',' elem_printf  */
#line 269 "trad12.y"
                                                    {
                                              sprintf (temp, "%s (princ %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1758 "trad12.tab.c"
    break;

  case 58: /* elem_printf: expresion  */
#line 274 "trad12.y"
                                            { yyval = yyvsp[0] ; }
#line 1764 "trad12.tab.c"
    break;

  case 59: /* elem_printf: STRING  */
#line 275 "trad12.y"
                                            { sprintf (temp, "\"%s\"", yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1771 "trad12.tab.c"
    break;

  case 60: /* expresion: termino  */
#line 279 "trad12.y"
                                            { yyval = yyvsp[0] ; }
#line 1777 "trad12.tab.c"
    break;

  case 61: /* expresion: expresion '+' expresion  */
#line 280 "trad12.y"
                                            { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1784 "trad12.tab.c"
    break;

  case 62: /* expresion: expresion '-' expresion  */
#line 282 "trad12.y"
                                            { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1791 "trad12.tab.c"
    break;

  case 63: /* expresion: expresion '*' expresion  */
#line 284 "trad12.y"
                                            { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1798 "trad12.tab.c"
    break;

  case 64: /* expresion: expresion '/' expresion  */
#line 286 "trad12.y"
                                            { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1805 "trad12.tab.c"
    break;

  case 65: /* expresion: expresion '%' expresion  */
#line 288 "trad12.y"
                                            { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1812 "trad12.tab.c"
    break;

  case 66: /* expresion: expresion OR expresion  */
#line 290 "trad12.y"
                                            { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1819 "trad12.tab.c"
    break;

  case 67: /* expresion: expresion AND expresion  */
#line 292 "trad12.y"
                                            { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1826 "trad12.tab.c"
    break;

  case 68: /* expresion: expresion EQ expresion  */
#line 294 "trad12.y"
                                            { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1833 "trad12.tab.c"
    break;

  case 69: /* expresion: expresion NEQ expresion  */
#line 296 "trad12.y"
                                            { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1840 "trad12.tab.c"
    break;

  case 70: /* expresion: expresion '<' expresion  */
#line 298 "trad12.y"
                                            { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1847 "trad12.tab.c"
    break;

  case 71: /* expresion: expresion LEQ expresion  */
#line 300 "trad12.y"
                                            { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1854 "trad12.tab.c"
    break;

  case 72: /* expresion: expresion '>' expresion  */
#line 302 "trad12.y"
                                            { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1861 "trad12.tab.c"
    break;

  case 73: /* expresion: expresion GEQ expresion  */
#line 304 "trad12.y"
                                            { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1868 "trad12.tab.c"
    break;

  case 74: /* expresion: '!' expresion  */
#line 306 "trad12.y"
                                            { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                              yyval.code = gen_code (temp) ; }
#line 1875 "trad12.tab.c"
    break;

  case 75: /* termino: operando  */
#line 310 "trad12.y"
                                            { yyval = yyvsp[0] ; }
#line 1881 "trad12.tab.c"
    break;

  case 76: /* termino: '+' operando  */
#line 311 "trad12.y"
                                                { yyval = yyvsp[-1] ; }
#line 1887 "trad12.tab.c"
    break;

  case 77: /* termino: '-' operando  */
#line 312 "trad12.y"
                                                { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                  yyval.code = gen_code (temp) ; }
#line 1894 "trad12.tab.c"
    break;

  case 78: /* operando: IDENTIF  */
#line 316 "trad12.y"
                                            { sprintf (temp, "%s", get_var_name(yyvsp[0].code)) ;
                                              yyval.code = gen_code (temp) ; }
#line 1901 "trad12.tab.c"
    break;

  case 79: /* operando: NUMBER  */
#line 318 "trad12.y"
                                            { sprintf (temp, "%d", yyvsp[0].value) ;
                                              yyval.code = gen_code (temp) ; }
#line 1908 "trad12.tab.c"
    break;

  case 80: /* operando: '(' expresion ')'  */
#line 320 "trad12.y"
                                            { yyval.code = gen_code (yyvsp[-1].code) ; }
#line 1914 "trad12.tab.c"
    break;

  case 81: /* operando: IDENTIF '(' lista_argumentos_opt ')'  */
#line 321 "trad12.y"
                                                        { sprintf (temp, "(%s %s)", get_var_name(yyvsp[-3].code), yyvsp[-1].code) ; 
                                                        yyval.code = gen_code (temp) ; }
#line 1921 "trad12.tab.c"
    break;

  case 82: /* operando: IDENTIF '[' expresion ']'  */
#line 323 "trad12.y"
                                            { sprintf (temp, "(aref %s %s)", get_var_name(yyvsp[-3].code), yyvsp[-1].code) ; 
                                            yyval.code = gen_code (temp) ; }
#line 1928 "trad12.tab.c"
    break;


#line 1932 "trad12.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 328 "trad12.y"
                            // SECCION 4    Codigo en C

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
