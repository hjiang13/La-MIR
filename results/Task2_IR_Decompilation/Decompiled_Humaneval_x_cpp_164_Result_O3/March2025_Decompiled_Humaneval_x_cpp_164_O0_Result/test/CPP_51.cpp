#include <string>
#include <algorithm>

std::string remove_vowels(const std::string& input) {
    std::string vowels = "AEIOUaeiou";
    std::string result;
    for (char c : input) {
        if (std::find(vowels.begin(), vowels.end(), c) == vowels.end()) {
            result += c;
        }
    }
    return result;
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
