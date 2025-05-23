int fib(int n) {
    int arr[100];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    if (n < 3) {
        return arr[n];
    }
    int i = 3;
    int a = 1;
    while (i <= n) {
        int b = arr[i - 2] + a;
        int c = arr[i - 3] + b;
        arr[i] = c;
        a = c;
        i++;
    }
    return arr[n];
}
