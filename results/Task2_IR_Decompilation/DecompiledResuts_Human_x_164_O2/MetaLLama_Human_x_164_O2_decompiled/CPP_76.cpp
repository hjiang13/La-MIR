bool is_simple_power(int n, int m) {
    if (n <= 0) return false;
    if (n == 1) return true;
    int i = 0;
    int p = 1;
    do {
        p *= m;
        i++;
        if (p > n) return false;
        if (p == n) return true;
    } while (i < 99);
    return false;
}
