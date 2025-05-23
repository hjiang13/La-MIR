#include <string>

void words_in_sentence(std::string& sret, std::string& s) {
    sret = s;
    if (s.size() > 15) {
        sret = s.substr(0, 15);
    }
}

int main() {
    std::string input = "Hello, World!";
    std::string result;
    
    words_in_sentence(result, input);
    
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
