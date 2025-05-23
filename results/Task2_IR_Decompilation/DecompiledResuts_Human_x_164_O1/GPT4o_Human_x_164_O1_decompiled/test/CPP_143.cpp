#include <string>

void words_in_sentence(std::string &result, const std::string &input) {
    size_t count = input.length();
    if (count > 15) {
        result.resize(count);
        switch (count) {
            case 1:
                result[0] = input[0];
                break;
            case 0:
                break;
            default:
                std::memcpy(&result[0], &input[0], count);
                break;
        }
    } else {
        switch (count) {
            case 1:
                result[0] = input[0];
                break;
            case 0:
                break;
            default:
                std::memcpy(&result[0], &input[0], count);
                break;
        }
    }
    
    result[count] = '\0';
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
