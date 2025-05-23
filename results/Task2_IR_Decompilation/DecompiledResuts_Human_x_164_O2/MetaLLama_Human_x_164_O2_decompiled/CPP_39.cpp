int prime_fib(int n) {
    int a = 1;
    int b = 2;
    int i = 0;
    while (i < n) {
        int temp = a + b;
        a = b;
        b = temp;
        i += (b % 2 == 0 || b % 3 == 0 || b % 4 == 0) ? 0 : 1;
    }
    return b;
}
