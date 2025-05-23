```cpp
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <iostream>

void reverse_delete(std::vector<std::string>& vec, const std::string& str1, const std::string& str2) {
    std::string temp;
    size_t index = 0;

    while (index < vec.size()) {
        if (vec[index] == str2) {
            vec.erase(vec.begin() + index);
        } else {
            ++index;
        }
    }

    if (str1.empty()) {
        vec.push_back(str1);
    } else {
        vec.push_back(str2);
    }
}

int main() {
    std::vector<std::string> my_vector = {"Hello", "World", "Test"};
    std::string str1 = "NewString";
    std::string str2 = "World";

    reverse_delete(my_vector, str1, str2);

    for (const auto& str : my_vector) {
        std::cout << str << std::endl;
    }

    return 0;
}
```