int a = 5, b = 2;
main () {
    puts("Evaluando expresiones logicas:");
    
    printf("Resultado 1: %d", a + b == 7 && !(a < b));
    printf("Resultado 2: %d", a % 2 != 0 || b >= 5);
}
//@ (main)
