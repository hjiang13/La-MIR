int fib(int n) {
    int fib_sequence[100];
    fib_sequence[0] = 0;
    fib_sequence[1] = 0;
    fib_sequence[2] = 2;
    fib_sequence[3] = 0;
    
    int result = 4;
    
    for (int i = 4; i <= n; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2] + fib_sequence[i-3] + fib_sequence[i-4];
    }
    
    return fib_sequence[n];
}
#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib4(5) == 4);
    assert (fib4(8) == 28);
    assert (fib4(10) == 104);
    assert (fib4(12) == 386);
}
