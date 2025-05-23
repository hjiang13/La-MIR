```cpp
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>

void even_odd_palindrome(std::vector<std::string>& result, int n) {
    if (n < 1) {
        result.push_back("0");
        result.push_back("0");
        return;
    }

    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    result.resize(2);
    result[0] = std::to_string(even_count);
    result[1] = std::to_string(odd_count);
}

extern "C" {
    void __gxx_personality_v0();
}
```