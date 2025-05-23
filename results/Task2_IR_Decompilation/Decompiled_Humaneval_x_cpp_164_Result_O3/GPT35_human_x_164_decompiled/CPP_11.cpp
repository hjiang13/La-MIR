```c
#include <string>

void string_xor(std::__cxx11::basic_string<char> &result, std::__cxx11::basic_string<char> &str1, std::__cxx11::basic_string<char> &str2) {
    result.clear();
    
    for (size_t i = 0; i < std::min(str1.size(), str2.size()); i++) {
        result.push_back(str1[i] ^ str2[i]);
    }
}

int main() {
    std::__cxx11::basic_string<char> str1 = "Hello";
    std::__cxx11::basic_string<char> str2 = "World";
    std::__cxx11::basic_string<char> result;
    
    string_xor(result, str1, str2);
    
    for (char c : result) {
        std::cout << c;
    }
    
    return 0;
}
```