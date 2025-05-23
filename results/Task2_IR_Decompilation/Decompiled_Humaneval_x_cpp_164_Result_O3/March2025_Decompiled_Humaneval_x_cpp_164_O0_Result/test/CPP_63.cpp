#include <iostream>
#include <vector>

int fibfibi(int n) {
    std::vector<int> fib(100, 0);
    fib[2] = 1;
    for (int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3];
    }
    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fibfibi(n) << std::endl;
    return 0;
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
