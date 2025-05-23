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
