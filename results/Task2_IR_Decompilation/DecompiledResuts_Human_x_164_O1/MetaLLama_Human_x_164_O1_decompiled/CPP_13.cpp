int greatest_common_divisor(int a, int b) {
    while (1) {
        int c = a < b ? a : b;
        int d = a < b ? b : a;
        int e = d % c;
        if (e == 0) break;
        a = c;
        b = e;
    }
    return c;
}
