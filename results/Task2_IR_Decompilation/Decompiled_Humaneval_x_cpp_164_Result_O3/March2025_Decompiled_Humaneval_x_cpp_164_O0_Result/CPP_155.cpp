```cpp
#include <vector>
#include <string>
#include <cstdlib>
#include <initializer_list>
#include <stdexcept>

std::vector<int> even_odd_count(int n) {
    std::string str = std::to_string(std::abs(n));
    int even_count = 0;
    int odd_count = 0;
    int index = 0;

    while (index < str.length()) {
        char c = str[index];
        int digit = static_cast<int>(c);
        if (digit % 2 == 1) {
            odd_count++;
        } else {
            even_count++;
        }
        index++;
    }

    std::initializer_list<int> init_list = {even_count, odd_count};
    std::vector<int> result(init_list);
    return result;
}
```