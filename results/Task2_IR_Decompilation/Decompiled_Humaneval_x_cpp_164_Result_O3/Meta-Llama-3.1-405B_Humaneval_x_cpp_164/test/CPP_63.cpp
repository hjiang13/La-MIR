#include <stdio.h>

int fib(int n) {
    int arr[100];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    if (n < 3) {
        return arr[n];
    }
    arr[3] = 1;
    if (n == 4) {
        return arr[3];
    }
    int i = 4;
    int j = 3;
    while (j < n) {
        arr[i] = arr[j - 1] + arr[j - 2] + arr[j - 3];
        arr[i + 1] = arr[i] + arr[j - 1] + arr[j - 2];
        j += 2;
        i += 2;
    }
    if (n % 2 == 0) {
        return arr[n];
    } else {
        return arr[n - 1] + arr[n - 2] + arr[n - 3];
    }
}

int main() {
    // You can test the function here
    // printf("%d\n", fib(10));
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
