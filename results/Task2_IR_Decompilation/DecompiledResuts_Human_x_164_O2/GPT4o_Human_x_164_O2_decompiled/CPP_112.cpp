```cpp
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

void reverse_delete(std::vector<std::string>& vec, const std::string& str1, const std::string& str2) {
    size_t size = vec.size();
    for (size_t i = 0; i < size; ++i) {
        if (vec[i] == str1 || vec[i] == str2) {
            vec.erase(vec.begin() + i);
            --i; // Adjust index after erase
            --size; // Update size
        }
    }
}

int main() {
    std::vector<std::string> vec = {"Hello", "World", "Foo", "Bar", "Baz"};
    std::string str1 = "Foo";
    std::string str2 = "Bar";
    reverse_delete(vec, str1, str2);
    
    for (const auto& str : vec) {
        std::cout << str << std::endl;
    }
    
    return 0;
}
```