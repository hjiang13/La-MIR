#include <string>

void remove_vowels(std::string& s) {
    static const char vowels[] = "AEIOUaeiou";
    std::__cxx11::basic_string<char> temp;

    for (char c : s) {
        bool is_vowel = false;
        for (char v : vowels) {
            if (c == v) {
                is_vowel = true;
                break;
            }
        }
        if (!is_vowel) {
            temp += c;
        }
    }

    s = temp;
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
