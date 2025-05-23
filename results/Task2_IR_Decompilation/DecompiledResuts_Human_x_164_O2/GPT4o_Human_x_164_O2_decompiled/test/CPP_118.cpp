#include <string>
#include <cstring>
#include <iostream>

std::string get_closest_vowel(std::string str) {
    std::string result;
    const char* vowels = "AEIOUaeiou";
    size_t len = str.size();
    
    if (len > 1) {
        for (size_t i = 0; i < len; ++i) {
            if (strchr(vowels, str[i]) != nullptr) {
                result += str[i];
            }
        }
    }

    return result;
}

int main() {
    std::string input = "Hello World";
    std::string closestVowel = get_closest_vowel(input);
    std::cout << "Closest vowels: " << closestVowel << std::endl;
    return 0;
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
