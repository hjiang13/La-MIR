```cpp
#include <string>

void remove_vowels(std::string& result, const std::string& input) {
    std::string temp;
    temp = "AEIOUaeiou";
    
    for (int i = 0; i < input.length(); i++) {
        bool is_vowel = false;
        for (int j = 0; j < temp.length(); j++) {
            if (input[i] == temp[j]) {
                is_vowel = true;
                break;
            }
        }
        if (!is_vowel) {
            result += input[i];
        }
    }
}

int main() {
    std::string input = "Hello World";
    std::string result;
    
    remove_vowels(result, input);
    
    return 0;
}
```