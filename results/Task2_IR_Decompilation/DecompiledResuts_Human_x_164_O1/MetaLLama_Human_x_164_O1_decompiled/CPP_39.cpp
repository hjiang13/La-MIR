int prime_fib(int n) {
    int a = 1;
    int b = 2;
    int c = 0;
    int i = 0;
    while (i < n) {
        int temp = a + b;
        a = b;
        b = temp;
        if (b < 4 || (b & 1) == 0) {
            i++;
            continue;
        }
        for (int j = 3; j * j <= b; j += 2) {
            if (b % j == 0) {
                goto next;
            }
        }
        i++;
        c = b;
        next:;
    }
    return c;
}
