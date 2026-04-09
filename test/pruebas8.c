int global_var = 10;
int flag;

main() {
    int local_var = 5;
    int result;

    flag = 1;
    result = 0;

    if (flag == 1) {
        puts("La bandera es verdadera");
        result = global_var + local_var;
    } else {
        puts("La bandera es falsa");
        result = 0;
    }

    while (local_var > 0) {
        printf("%d", local_var);
        local_var = local_var - 1;
    }
}