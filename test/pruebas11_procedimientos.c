saludar(int veces) {
    print(veces);
    return 0;
}

duplicar(int n) {
    return n * 2;
}

main() {
    int a;
    int b;
    
    a = 10;

    // Llamada como procedimiento (Sentencia aislada) */
    saludar(a);

    // Mala praxis permitida: llamar a función con retorno como procedimiento, el valor calculado (20) se ignora en la traducción
    duplicar(a); 

    // Llamada como operando en una asignación
    b = duplicar(a);
    
    // Llamada anidada: un procedimiento que recibe el resultado de una función
    saludar(duplicar(b));

    return 0;
}