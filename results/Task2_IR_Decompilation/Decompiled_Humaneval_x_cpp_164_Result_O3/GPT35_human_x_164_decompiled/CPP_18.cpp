```cpp
#include <iostream>
#include <string>

int how_many_times(std::string* str1, std::string* str2) {
    if (str1->size() == 0) {
        return 0;
    } else {
        std::string temp_str = str2->substr(0, str1->size());
        if (temp_str.compare(*str1) == 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    std::string str1 = "hello";
    std::string str2 = "hello world";
    
    int result = how_many_times(&str1, &str2);
    
    std::cout << result << std::endl;
    
    return 0;
}
```