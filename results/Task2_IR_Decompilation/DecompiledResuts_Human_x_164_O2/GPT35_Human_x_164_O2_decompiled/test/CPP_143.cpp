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
