#include <string>
#include <cstring>

void words_in_sentence(std::string &result, const std::string &input) {
    size_t length = input.length();
    if (length > 15) {
        result.resize(length);
        std::memcpy(&result[0], input.c_str(), length);
    } else {
        result = input;
    }
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
