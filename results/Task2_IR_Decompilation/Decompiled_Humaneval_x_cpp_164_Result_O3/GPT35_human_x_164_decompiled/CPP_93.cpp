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
```