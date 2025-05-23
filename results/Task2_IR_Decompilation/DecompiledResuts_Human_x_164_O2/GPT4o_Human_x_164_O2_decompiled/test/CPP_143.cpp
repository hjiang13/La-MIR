#include <string>
#include <cstring>

void words_in_sentence(std::string& output, const std::string& input) {
    size_t length = input.size();
    if (length > 15) {
        output.resize(length);
        std::memcpy(&output[0], input.c_str(), length);
        output[length] = '\0';
    } else {
        output = input;
    }
    
    size_t wordCount = 0;
    for (size_t i = 0; i < length; ++i) {
        if (input[i] == ' ') {
            wordCount++;
        }
    }
    
    if (wordCount > 0) {
        output.insert(0, "Words in sentence: ");
        output += std::to_string(wordCount);
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
