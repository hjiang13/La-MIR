```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> reverse_delete(std::string str1, std::string str2) {
    std::string result;
    for (size_t i = 0; i < str1.length(); ++i) {
        char c = str1[i];
        auto it = std::find(str2.begin(), str2.end(), c);
        if (it == str2.end()) {
            result += c;
        }
    }
    if (result.empty()) {
        return {result, "True"};
    } else {
        std::string reversed_result(result.rbegin(), result.rend());
        if (reversed_result == result) {
            return {result, "True"};
        } else {
            return {result, "False"};
        }
    }
}

int main() {
    std::string str1 = "example";
    std::string str2 = "ample";
    std::vector<std::string> result = reverse_delete(str1, str2);
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }
    return 0;
}
```