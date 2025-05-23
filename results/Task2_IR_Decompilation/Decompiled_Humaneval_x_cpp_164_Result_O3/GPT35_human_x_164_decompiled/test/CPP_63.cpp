```c
#include <stdio.h>

int fib(int n) {
    int arr[100];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;

    if (n < 3) {
        return arr[n];
    }

    for (int i = 3; i <= n; i++) {
        if (i % 2 == 0) {
            arr[i] = arr[i - 1] + arr[i - 2];
        } else {
            arr[i] = arr[i - 1] + arr[i - 3];
        }
    }

    return arr[n];
}

int main() {
    int n = 10;
    int result = fib(n);
    printf("Fibonacci number at position %d is %d\n", n, result);
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fibfib(2) == 1);
    assert (fibfib(1) == 0);
    assert (fibfib(5) == 4);
    assert (fibfib(8) == 24);
    assert (fibfib(10) == 81);
    assert (fibfib(12) == 274);
    assert (fibfib(14) == 927);
}
