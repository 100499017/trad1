int global = 10;

main() {
    int opcion = 2;
    int resultado = 0;

    switch (opcion) {
        case 1:
            resultado = 100;
            break;
        case 2:
            resultado = 200;
            puts("Opcion 2 elegida");
            break;
        default:
            resultado = global;
            break;
    }
}