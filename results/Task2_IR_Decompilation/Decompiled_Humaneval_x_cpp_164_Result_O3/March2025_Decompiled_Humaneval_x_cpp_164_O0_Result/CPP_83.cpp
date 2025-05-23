```cpp
#include <iostream>

int starts_one_ends(int input) {
    if (input < 1) {
        return 0;
    } else if (input == 1) {
        return 1;
    } else {
        int result = 18;
        for (int i = 2; i < input; ++i) {
            result *= 10;
        }
        return result;
    }
}

int main() {
    int input;
    std::cin >> input;
    std::cout << starts_one_ends(input) << std::endl;
    return 0;
}
```