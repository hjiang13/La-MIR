#include <cstdint>

using namespace std;

int32_t fibi(int32_t n) {
    int32_t arr[1000];  // Array to store intermediate values
    
    arr[0] = 0;
    arr[1] = 1;
    
    if (n < 2) {
        return arr[n];
    }
    
    arr[2] = 1;  // Base case for n >= 2
    
    // Main calculation loop
    for (int64_t i = 3; i <= n; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    return arr[n];
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
