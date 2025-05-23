#include <iostream>

int fib4i(int n) {
    int arr[100] = {0, 0, 2, 0};
    
    if (n < 4) {
        return arr[3];
    }

    for (int i = 4; i <= n; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    return arr[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib4i(n) << std::endl;
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
