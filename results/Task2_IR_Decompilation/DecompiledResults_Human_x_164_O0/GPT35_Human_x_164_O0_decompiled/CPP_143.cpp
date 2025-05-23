```cpp
#include <string>

void words_in_sentence(std::string& result, std::string& input) {
    result = "";
    std::string temp = "";
    
    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        
        if (c != ' ') {
            temp += c;
        } else {
            result += temp;
            result += " ";
            temp = "";
        }
    }
    
    result += temp;
}

int main() {
    std::string input = "Hello World";
    std::string result;
    
    words_in_sentence(result, input);
    
    return 0;
}
```