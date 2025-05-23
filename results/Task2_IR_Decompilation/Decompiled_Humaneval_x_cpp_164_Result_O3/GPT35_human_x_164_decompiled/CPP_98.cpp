```cpp
#include <iostream>
#include <string>

int count_upper(std::__cxx11::basic_string<char> str) {
    const char vowels[] = "AEIOU";
    int count = 0;

    for (char c : str) {
        for (char vowel : vowels) {
            if (c == vowel) {
                count++;
                break;
            }
        }
    }

    return count;
}

int main() {
    std::__cxx11::basic_string<char> str = "Hello World";
    int result = count_upper(str);
    
    std::cout << "Number of uppercase vowels: " << result << std::endl;

    return 0;
}
```