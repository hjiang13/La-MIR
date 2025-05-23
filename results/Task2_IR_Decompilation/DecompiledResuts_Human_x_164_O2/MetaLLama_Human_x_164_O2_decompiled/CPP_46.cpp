#include <stdio.h>

int fib4(int n) {
    int arr[100];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 2;
    arr[3] = 0;

    if (n < 4) {
        return arr[n];
    }

    arr[4] = 2;

    if (n == 5) {
        return arr[4];
    }

    int i = 5;
    int j = 4;
    int k = 2;
    int l = 2;

    while (1) {
        int m = i - 3;
        int o = i - 1;
        int p = arr[o];
        int q = arr[m];
        int r = p + k;
        int s = r + l;
        int t = s + q;
        arr[i] = t;

        i += 1;
        int u = i - 3;
        int v = i - 1;
        int w = arr[v];
        int x = arr[u];
        int y = w + t;
        int z = y + p;
        int aa = z + x;
        arr[i] = aa;

        i += 1;
        j += 2;
        k = aa;
        l = t;

        if (j == n) {
            break;
        }
    }

    return arr[n];
}
