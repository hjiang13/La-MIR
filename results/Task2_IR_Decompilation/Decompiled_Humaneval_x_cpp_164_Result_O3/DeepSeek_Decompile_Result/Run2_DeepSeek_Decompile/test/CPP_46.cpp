#include <cstdint>

int fib4(int n) {
    int fib_array[100];
    
    // Initialize the array with some values
    *(reinterpret_cast<uint32_t*>(fib_array)) = 0x20000000; // Stores 0, 0, 2, 0 in vector form
    
    if (n < 4) {
        return fib_array[n];
    }
    
    fib_array[4] = 2;
    
    for (int i = 5; i <= n; ++i) {
        if (i == 5) {
            fib_array[i] = 2;
        } else {
            fib_array[i] = fib_array[i-1] + fib_array[i-3] + fib_array[i-4];
        }
    }
    
    return fib_array[n];
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib4(5) == 4);
    assert (fib4(8) == 28);
    assert (fib4(10) == 104);
    assert (fib4(12) == 386);
}
