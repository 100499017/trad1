// Función con retorno estructurado (Punto i)
sumar_estructurado(a, b) {
    int resultado;
    resultado = a + b;
    return resultado;
}

// Función con retornos intermedios "mala praxis" (Punto ii)
valor_absoluto(n) {
    if (n < 0) {
        return -n;  // Retorno intermedio (Punto ii) duda sobre como añadirlo
    }
    return n;       // Retorno final (Punto i)
}

// Función que se usará como procedimiento (Punto d)
test_procedimiento(x) {
    printf("no imprime", " Ejecutando funcion auxiliar con valor: ", x);
    return 100; // Devuelve un valor, pero lo ignoraremos
}

main() {
    int x;
    int y;

    // 1. Llamada dentro de asignación (Uso normal)
    x = sumar_estructurado(10, 5);
    printf("no imprime", " Resultado suma: ", x);

    // 2. Llamada con retorno intermedio
    y = valor_absoluto(-25);
    printf("no imprime", " Valor absoluto de -25: ", y);

    // 3. LLAMADA COMO PROCEDIMIENTO (Punto d)
    // Aquí ignoramos el '100' que devuelve la función. 
    // Debe aparecer en Lisp como una sentencia (test_procedimiento 50)
    test_procedimiento(50);

    // 4. Llamada como argumento de otra función (Punto d)
    printf("no imprime", " Suma anidada: ", sumar_estructurado(5, valor_absoluto(-5)));
}