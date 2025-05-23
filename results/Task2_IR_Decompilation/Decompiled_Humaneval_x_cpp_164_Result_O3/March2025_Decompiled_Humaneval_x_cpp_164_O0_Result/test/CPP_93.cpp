#include <string>
#include <algorithm>

std::string encode(const std::string& input) {
    std::string vowels = "aeiouAEIOU";
    std::string result;

    for (char c : input) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        } else if (c >= 'A' && c <= 'Z') {
            c += 32;
        }

        if (std::find(vowels.begin(), vowels.end(), c) != vowels.end()) {
            c += 2;
        }

        result += c;
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (encode("TEST") == "tgst");
    assert (encode("Mudasir") == "mWDCSKR");
    assert (encode("YES") == "ygs");
    assert (encode("This is a message") == "tHKS KS C MGSSCGG");
    assert (encode("I DoNt KnOw WhAt tO WrItE") == "k dQnT kNqW wHcT Tq wRkTg");
}
