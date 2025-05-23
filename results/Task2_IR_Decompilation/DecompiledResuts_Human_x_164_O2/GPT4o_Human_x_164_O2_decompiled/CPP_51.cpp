```cpp
#include <string>

void remove_vowels(std::string &result, const std::string &input) {
    const char* vowels = "AEIOUaeiou";
    size_t input_length = input.length();
    result.reserve(input_length); // Reserve space in result string

    for (size_t i = 0; i < input_length; ++i) {
        char current_char = input[i];
        bool is_vowel = false;

        for (size_t j = 0; j < 10; ++j) {
            if (current_char == vowels[j]) {
                is_vowel = true;
                break;
            }
        }

        if (!is_vowel) {
            result += current_char; // Append non-vowel characters to result
        }
    }
}
```