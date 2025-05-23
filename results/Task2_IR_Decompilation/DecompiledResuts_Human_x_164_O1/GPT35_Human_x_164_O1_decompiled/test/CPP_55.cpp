#include <stdio.h>

int f(int x) {
    int arr[1000] = {0};
    
    if (x < 2) {
        return arr[x];
    } else {
        for (int i = 2; i <= x; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[x];
    }
}

int main() {
    int result = f(10);
    printf("Result: %d\n", result);
    return 0;
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
