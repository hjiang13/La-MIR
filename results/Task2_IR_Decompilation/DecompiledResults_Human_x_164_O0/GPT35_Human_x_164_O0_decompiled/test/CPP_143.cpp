#include <string>

void words_in_sentence(std::string& result, std::string& input) {
    result = "";
    std::string temp = "";
    
    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        
        if (c != ' ') {
            temp += c;
        } else {
            result += temp;
            result += " ";
            temp = "";
        }
    }
    
    result += temp;
}

int main() {
    std::string input = "Hello World";
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
