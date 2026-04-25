sumar_estructurado(int a, int b) {
    int resultado;
    resultado = a + b;
    return resultado;
}

valor_absoluto(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

test_procedimiento(int x) {
    printf("no imprime", " Ejecutando funcion auxiliar con valor: ", x);
    return 100;
}

main() {
    int x;
    int y;
    int z;

    x = sumar_estructurado(10, 5);
    printf("no imprime", " Resultado suma: ", x);

    y = valor_absoluto(-25);
    printf("no imprime", " Valor absoluto de -25: ", y);

    z = 100 + valor_absoluto(-50); 
    printf("no imprime", " Operacion mixta (100 + |-50|): ", z);

    test_procedimiento(50);

    printf("no imprime", " Suma anidada: ", sumar_estructurado(5, valor_absoluto(-5)));
}
//@ (main)
