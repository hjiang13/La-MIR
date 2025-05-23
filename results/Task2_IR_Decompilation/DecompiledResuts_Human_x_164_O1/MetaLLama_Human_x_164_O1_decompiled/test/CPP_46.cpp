#include <stdio.h>

int fib(int n) {
    int arr[100];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 2;
    arr[3] = 0;

    if (n < 4) {
        return arr[n];
    }

    int i = 4;
    int temp = 0;
    while (i <= n + 1) {
        temp = arr[i - 2] + arr[i - 3] + arr[i - 4];
        arr[i] = temp;
        i++;
    }

    return arr[n];
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib4(5) == 4);
    assert (fib4(8) == 28);
    assert (fib4(10) == 104);
    assert (fib4(12) == 386);
}
