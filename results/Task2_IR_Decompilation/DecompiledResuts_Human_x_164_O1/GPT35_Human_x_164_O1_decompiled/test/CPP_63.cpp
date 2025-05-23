#include <stdint.h>

int fib(int n) {
    int arr[100] = {0};
    
    if (n < 3) {
        return arr[n];
    }
    
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    return arr[n];
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
