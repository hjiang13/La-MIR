```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

int count_distinct_characters(std::string str) {
    std::vector<char> distinct_chars;
    for (char c : str) {
        c = std::tolower(c);
        if (std::find(distinct_chars.begin(), distinct_chars.end(), c) == distinct_chars.end()) {
            distinct_chars.push_back(c);
        }
    }
    return distinct_chars.size();
}
```