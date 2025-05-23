```cpp
#include <iostream>
#include <string>
#include <vector>

void Strongest_Extension(std::string &result, const std::string &input, const std::vector<std::string> &vec) {
    std::string temp;
    size_t inputSize = input.size();
    
    if (inputSize > 15) {
        temp.resize(inputSize);
        for (size_t i = 0; i < inputSize; ++i) {
            char c = input[i];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                temp[i] = c;
            }
        }
        result = temp;
    } else {
        result = "Default String";
    }
}

int main() {
    std::string result;
    std::string input = "Example Input String";
    std::vector<std::string> vec = {"String1", "String2", "String3"};
    
    Strongest_Extension(result, input, vec);
    std::cout << result << std::endl;
    
    return 0;
}
```