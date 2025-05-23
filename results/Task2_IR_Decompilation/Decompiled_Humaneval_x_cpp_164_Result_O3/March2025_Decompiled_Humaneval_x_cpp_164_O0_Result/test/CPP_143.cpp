#include <string>
#include <stdexcept>

std::string words_in_sentence(const std::string& input) {
    std::string result;
    std::string temp;
    bool isWord = false;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (c != ' ') {
            temp += c;
            isWord = true;
        } else {
            if (isWord) {
                if (temp.length() >= 2) {
                    bool isPrime = true;
                    for (int j = 2; j * j <= temp.length(); ++j) {
                        if (temp.length() % j == 0) {
                            isPrime = false;
                            break;
                        }
                    }
                    if (isPrime) {
                        result += temp + " ";
                    }
                }
                temp.clear();
            }
            isWord = false;
        }
    }

    if (!temp.empty() && temp.length() >= 2) {
        bool isPrime = true;
        for (int j = 2; j * j <= temp.length(); ++j) {
            if (temp.length() % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            result += temp;
        }
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (words_in_sentence("This is a test") == "is");
    assert (words_in_sentence("lets go for swimming") == "go for");
    assert (words_in_sentence("there is no place available here") == "there is no place");
    assert (words_in_sentence("Hi I am Hussein") == "Hi am Hussein");
    assert (words_in_sentence("go for it") == "go for it");
    assert (words_in_sentence("here") == "");
    assert (words_in_sentence("here is") == "is");
}
