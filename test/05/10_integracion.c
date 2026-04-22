#define inc(x) (++(x))
#define dec(x) (--(x))

int global_val = 0;

procesar(int x) {
    switch (x) {
        case 1:
            global_val = 100;
            break;
        default:
            global_val = -1;
            break;
    }
    return global_val;
}

main() {
    int i = 0;
    int vector[3];
    
    for (i = 0; i < 3; inc(i)) {
        vector[i] = procesar(1);
        printf("%d%c", vector[i], " ");
    }
}
//@ (main)
