int n = 5;

cuenta_atras() {
    if (n > 0) {
        printf("Numero: ", n);
        n = n - 1;
        cuenta_atras(); // Llamada recursiva
    }
}

main() {
    puts("Iniciando cuenta atras recursiva:");
    cuenta_atras();
    puts("¡Boom!");
}