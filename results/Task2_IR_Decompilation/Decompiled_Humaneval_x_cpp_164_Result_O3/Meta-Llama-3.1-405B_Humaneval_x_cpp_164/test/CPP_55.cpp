int f(int n) {
    int a[1000];
    a[0] = 0;
    a[1] = 1;
    if (n < 2) return a[n];
    a[2] = 1;
    if (n == 3) return a[n];
    int i, j, k, t;
    for (i = 3; i <= n; i++) {
        if (i % 4 == 0) {
            for (j = i - 3; j <= i; j++) {
                a[j] = a[j - 1] + a[j - 2];
            }
        } else {
            k = i - (i % 4);
            t = a[k - 1] + a[k - 2];
            for (j = k; j <= i; j++) {
                a[j] = t + a[j - 1];
                t = a[j];
            }
        }
    }
    return a[n];
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib(10) == 55);
    assert (fib(1) == 1);
    assert (fib(8) == 21);
    assert (fib(11) == 89);
    assert (fib(12) == 144);
}
