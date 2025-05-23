#include <string>
#include <algorithm>

std::string get_closest_vowel(const std::string& input) {
    std::string result;
    std::string vowels = "AEIOUaeiou";
    int length = input.length() - 2;

    while (length >= 1) {
        char current_char = input[length];
        if (std::find(vowels.begin(), vowels.end(), current_char) != vowels.end()) {
            result = current_char;
            return result;
        }

        char next_char = input[length + 1];
        if (std::find(vowels.begin(), vowels.end(), next_char) != vowels.end()) {
            result = next_char;
            return result;
        }

        char prev_char = input[length - 1];
        if (std::find(vowels.begin(), vowels.end(), prev_char) != vowels.end()) {
            result = prev_char;
            return result;
        }

        length--;
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (get_closest_vowel("yogurt") == "u");
    assert (get_closest_vowel("full") == "u");
    assert (get_closest_vowel("easy") == "");
    assert (get_closest_vowel("eAsy") == "");
    assert (get_closest_vowel("ali") == "");
    assert (get_closest_vowel("bad") == "a");
    assert (get_closest_vowel("most") =="o");
    assert (get_closest_vowel("ab") == "");
    assert (get_closest_vowel("ba") == "");
    assert (get_closest_vowel("quick") == "");
    assert (get_closest_vowel("anime") == "i");
    assert (get_closest_vowel("Asia") == "");
    assert (get_closest_vowel("Above") == "o");
}
