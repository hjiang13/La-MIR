#include <stdio.h>

int f(int n) {
    int arr[1000];
    arr[0] = 0;
    arr[1] = 1;
    if (n < 2) {
        return arr[n];
    }
    arr[2] = 1;
    if (n == 3) {
        return arr[2];
    }
    int i, j;
    for (i = 3, j = 1; i <= n; i += 4, j++) {
        arr[i] = arr[i - 1] + j;
        arr[i + 1] = arr[i] + arr[i - 1];
        arr[i + 2] = arr[i + 1] + arr[i];
        arr[i + 3] = arr[i + 2] + arr[i + 1];
    }
    return arr[n];
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
