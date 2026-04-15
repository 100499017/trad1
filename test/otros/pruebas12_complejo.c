main() {
    int b[5];
    int i;
    
    i = 0;
    while (i < 5) {
        b[i] = i * 10;
        i = i + 1;
    }

    print(b[i - 1]); // Imprime b[4], que es 40
    
    b[i - 5] = 999;  // Modifica b[0]
    print(b[0]);     // Imprime 999
    
    return 0;
}