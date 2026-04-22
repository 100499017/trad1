int x = 15;
int y = 5;
int res = 0;

main() {
    puts("Probando operaciones aritméticas:");
    res = x + y;
    printf("%d%c", res, " ");
    
    res = x - y;
    printf("%d%c", res, " ");

    res = x * y;
    printf("%d%c", res, " ");

    res = x / y;
    printf("%f%c", res, " ");

    res = x % y;
    printf("%d", res);
}
//@ (main)
