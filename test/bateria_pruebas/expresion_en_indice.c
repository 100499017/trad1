main() {
    int b[5];
    int i;
    
    i = 0;
    puts("Rellenando vector (0, 10, 20, 30, 40):");
    while (i < 5) {
        b[i] = i * 10;
        puts(" ");
        printf("", "Guardado en la posición: ", i, ", el valor: ", b[i]);
        i = i + 1;
    }

    puts(" ");
    printf("", "Ultimo elemento (i-1): ", b[i - 1]);
    
    b[i - 5] = 999;

    puts("Vector tras modificar la posicion 0:");
    i = 0;
    while (i < 5) {
        puts(" ");
        printf("", "Guardado en la posición: ", i, ", el valor: ", b[i]);
        i = i + 1;
    }
}
//@ (main)
