#include <iostream>

int fib4i(int n) {
    int arr[100] = {0, 0, 2, 0};
    
    if (n < 4) {
        arr[n] = 2;
    } else {
        for (int i = 5; i <= n; ++i) {
            int a = arr[i - 1];
            int b = arr[i - 2];
            int c = arr[i - 3];
            arr[i] = a + b + c;
        }
    }
    return arr[n];
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "fib4i(" << n << ") = " << fib4i(n) << std::endl;
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
