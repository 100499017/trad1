int contador = 10;

incrementar() {
    contador = contador + 5;
    printf("no imprime", " Contador dentro de la funcion: ", contador);
}

main() {
    printf("no imprime", " Contador inicial: ", contador);
    incrementar();
    incrementar();
    printf("no imprime", " Contador final tras dos llamadas: ", contador);
}