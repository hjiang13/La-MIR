```c++
#include <string>

void encode(std::string &result, const std::string &input) {
    const char vowels[] = "aeiouAEIOU";

    result.clear();

    for (char c : input) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            bool isVowel = false;
            for (char vowel : vowels) {
                if (c == vowel) {
                    isVowel = true;
                    break;
                }
            }

            if (isVowel) {
                result += c;
            } else {
                result += c + 2;
            }
        }
    }
}

int main() {
    std::string input = "Hello, World!";
    std::string result;
    encode(result, input);

    return 0;
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
