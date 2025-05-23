```c
#include <iostream>
#include <string>

int vowels_count(std::string* str) {
    int count = 0;
    for (int i = 0; i < str->length(); i++) {
        char c = (*str)[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    std::string input = "aeiouAEIOU";
    int result = vowels_count(&input);
    std::cout << "Number of vowels: " << result << std::endl;
    return 0;
}
```