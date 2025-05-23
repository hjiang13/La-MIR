#include <string>
#include <cstring>

void encode(std::string &output, const std::string &input) {
    output.clear();
    for (size_t i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') {
            output += ch - 32;
        } else if (ch >= 'A' && ch <= 'Z') {
            output += ch + 32;
        } else {
            output += ch;
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
