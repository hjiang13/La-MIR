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
    
    for (int i = 4; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    
    return arr[n];
}

int main() {
    int n = 10;
    int result = fib(n);
    printf("Fibonacci number at position %d is: %d\n", n, result);
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib4(5) == 4);
    assert (fib4(8) == 28);
    assert (fib4(10) == 104);
    assert (fib4(12) == 386);
}
