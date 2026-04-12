int v[10];

mi_max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

main() {
    int m;
    v[0] = 10;
    v[1] = 20;
    m = mi_max(v[0], v[1]);
    printf("no imprime", "El máx de (10, 20) es: ", m);
}