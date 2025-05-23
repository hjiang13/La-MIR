int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib4(5) == 4);
    assert (fib4(8) == 28);
    assert (fib4(10) == 104);
    assert (fib4(12) == 386);
}
