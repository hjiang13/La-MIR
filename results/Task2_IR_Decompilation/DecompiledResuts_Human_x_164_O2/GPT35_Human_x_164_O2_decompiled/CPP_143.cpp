```cpp
#include <string>

void words_in_sentence(std::__cxx11::basic_string<char>& s, std::__cxx11::basic_string<char>& sentence) {
    std::__cxx11::basic_string<char> temp;

    if (sentence.size() > 15) {
        temp = sentence;
    } else {
        for (size_t i = 0; i < sentence.size(); ++i) {
            temp.push_back(sentence[i]);
        }
    }

    s = temp;
}
```