```cpp
#include <string>

void words_in_sentence(std::string& s, std::string& sentence) {
    if (sentence.size() > 15) {
        s = sentence.substr(0, 0);
    } else {
        s = sentence;
    }
}

int main() {
    std::string s;
    std::string sentence = "Hello, World!";
    
    words_in_sentence(s, sentence);
    
    return 0;
}
```