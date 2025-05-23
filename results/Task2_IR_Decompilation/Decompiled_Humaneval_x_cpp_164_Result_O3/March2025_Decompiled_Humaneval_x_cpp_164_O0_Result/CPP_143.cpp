```cpp
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
```