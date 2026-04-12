// Caso 1: Cero argumentos
saludar() {
    puts("Hola, ejecutando programa de pruebas...");
}

// Caso 2: Un único argumento
cuadrado(n) {
    int r;
    r = n * n;
    printf("Caso 2", " El cuadrado de ", n, " es: ", r);
}

// Caso 3: Varios argumentos (2 en este caso)
media(a, b) {
    int res;
    res = (a + b) / 2;
    printf("Caso 3", " La media de ", a, " y ", b, " es: ", res);
}

// Caso 4: Varios argumentos (3 en este caso) para verificar el orden
division_total(a, b, c) {
    int res;
    res = (a / b) / c;
    printf("Caso 4", " El resultado de (", a, " / ", b, ") / ", c, " es: ", res);
}

main() {
    saludar();                      // Prueba 0 argumentos
    cuadrado(5);                    // Prueba 1 argumento   (25)
    media(10, 20);                  // Prueba 2 argumentos  (15)
    division_total(100, 5, 2);      // Prueba 3 argumentos  (10)
}