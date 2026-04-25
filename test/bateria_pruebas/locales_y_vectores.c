int x = 10;
int v[5];

funcion_secundaria() {
    int x = 20;
    int v[3];
    
    v[0] = x;
    printf("%s%d", "Función secundaria: ", v[0]);
}

main() {
    int x = 30;
    int v[2];
    
    v[0] = x;
    
    funcion_secundaria();
    
    printf("%s%d", "Función main: ", v[0]);
}
//@ (main)
