#include <string>

void remove_vowels(std::string& result, const std::string& input) {
    result.clear();
    for (char c : input) {
        if (!(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
              c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            result += c;
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
