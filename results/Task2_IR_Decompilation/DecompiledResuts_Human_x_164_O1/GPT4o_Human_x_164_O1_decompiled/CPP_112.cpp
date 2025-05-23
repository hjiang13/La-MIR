```cpp
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

void reverse_delete(std::vector<std::string>& vec, const std::string& str1, const std::string& str2) {
    if (vec.empty() || str1.empty() || str2.empty()) {
        return;
    }

    size_t length1 = str1.size();
    size_t length2 = str2.size();

    for (size_t i = 0; i < length1; ++i) {
        if (str1[i] == str2[i]) {
            continue;
        }
        break;
    }

    if (length1 > 15) {
        std::string newStr1 = str1;
        newStr1.resize(length1);
        vec.push_back(newStr1);
    } else {
        std::string newStr2 = str2;
        newStr2.resize(length2);
        vec.push_back(newStr2);
    }

    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == str1 || vec[i] == str2) {
            vec.erase(vec.begin() + i);
            --i;
        }
    }
}

int main() {
    std::vector<std::string> vec;
    std::string str1 = "Hello";
    std::string str2 = "World";

    reverse_delete(vec, str1, str2);

    for (const auto& s : vec) {
        std::cout << s << std::endl;
    }

    return 0;
}
```