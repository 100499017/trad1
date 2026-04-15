int a = 1;
int b;

main () {
    if (a == 0) {
        b = 123;
    } else {
        b = 456;
        a = 2;
    }
    printf("%d", b);
}
