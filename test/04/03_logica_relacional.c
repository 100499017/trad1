int a = 1;
int b = 0;

main() {
    puts("Probando logica y relacionales:");
    if (a > b) {
        puts("1 es mayor a 0");
    }

    if (b < a) {
        puts("0 es menor que 1");
    }

    if (a >= b) {
        puts("1 es mayor o igual a 0");
    }

    if (b <= a) {
        puts("0 es menor o igual a 1");
    }

    if (a == b) {
        puts("1 es igual a 0");
    }

    if (a != b) {
        puts("1 es distinto de 0");
    }
    
    if (a && !b) {
        puts("A es verdadero y B es falso");
    }

    if (a || b) {
        puts("A o B es verdadero");
    }
}
//@ (main)
