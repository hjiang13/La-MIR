#include <iostream>

extern "C" int f(int n) {
    int array[1000] = {0};
    array[1] = 1;

    if (n < 2) {
        return array[n];
    }

    for (int i = 2; i <= n; ++i) {
        array[i] = array[i - 1] + array[i - 2];
    }

    return array[n];
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
