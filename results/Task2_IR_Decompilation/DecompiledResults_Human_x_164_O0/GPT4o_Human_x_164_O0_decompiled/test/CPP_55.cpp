#include <iostream>

extern "C" int f(int b) {
    int arr[1000] = {0, 1};
    int x = 2;

    for (int i = 0; i <= b; ++i) {
        int a = arr[i];
        int b_val = arr[i - 1];
        arr[i + 1] = a + b_val;
    }

    return arr[b];
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
