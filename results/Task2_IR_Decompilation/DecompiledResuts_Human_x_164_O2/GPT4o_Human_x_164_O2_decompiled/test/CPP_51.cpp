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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (remove_vowels("") == "");
    assert (remove_vowels("abcdef\nghijklm") == "bcdf\nghjklm");
    assert (remove_vowels("fedcba") == "fdcb");
    assert (remove_vowels("eeeee") == "");
    assert (remove_vowels("acBAA") == "cB");
    assert (remove_vowels("EcBOO") == "cB");
    assert (remove_vowels("ybcd") == "ybcd");
}
