int f(int n) {
    int a[1000];
    a[0] = 0;
    a[1] = 1;
    if (n < 2) return a[n];
    for (int i = 2; i <= n; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}
