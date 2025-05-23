```c
#include <vector>
#include <iostream>

void tr(std::vector<int>& v, int n) {
    if (n == 0) {
        v.clear();
    } else if (n < 2) {
        if (n == 1) {
            v.push_back(1);
        }
    } else {
        int prev = 1;
        int curr = 1;
        v.push_back(prev);
        v.push_back(curr);
        for (int i = 2; i < n; i++) {
            int next = prev + curr;
            v.push_back(next);
            prev = curr;
            curr = next;
        }
    }
}

int main() {
    std::vector<int> fib;
    tr(fib, 10);
    for (int i : fib) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
```