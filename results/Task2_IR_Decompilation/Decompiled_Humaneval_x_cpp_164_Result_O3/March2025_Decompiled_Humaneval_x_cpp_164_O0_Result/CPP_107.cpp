```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> even_odd_palindrome(int n) {
    std::vector<int> result;
    int even_count = 0;
    int odd_count = 0;
    for (int i = 1; i <= n; ++i) {
        std::string str = std::to_string(i);
        std::string rev_str(str.rbegin(), str.rend());
        if (str == rev_str) {
            if (i % 2 == 0) {
                ++even_count;
            } else {
                ++odd_count;
            }
        }
    }
    result.push_back(even_count);
    result.push_back(odd_count);
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> result = even_odd_palindrome(n);
    std::cout << "Even count: " << result[0] << ", Odd count: " << result[1] << std::endl;
    return 0;
}
```