#include <string>
#include <algorithm>

void encode(std::string &output, const std::string &input) {
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            output += c - 32;
        } else if (c >= 'A' && c <= 'Z') {
            output += c + 32;
        } else {
            output += c;
        }
    }
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
