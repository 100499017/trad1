int limite = 3;

main () {
    int i;
    int suma = 0;

    for (i = 0; i < limite; inc(i)) {
        suma = suma + i;
        if (suma == 2) {
            limite = limite - 1;
        }
    }
}