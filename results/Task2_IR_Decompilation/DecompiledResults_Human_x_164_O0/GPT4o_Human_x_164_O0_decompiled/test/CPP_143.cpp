#include <string>

struct Result {
    char* address;
    int code;
};

extern "C" Result words_in_sentence(std::string& str1, const std::string& str2) {
    std::string temp;
    std::string result;
    int count = 0;
    bool valid = false;

    while (true) {
        if (str1.size() > 0) {
            str1.pop_back();
            valid = true;
        } else {
            break;
        }

        if (valid) {
            for (size_t i = 0; i < str1.size(); ++i) {
                if (str1[i] != ' ') {
                    temp += str1[i];
                    count++;
                } else {
                    if (count > 0) {
                        result += temp + " ";
                        temp.clear();
                        count = 0;
                    }
                }
            }
            if (count > 0) {
                result += temp;
            }
        }
    }

    str1 = result;
    return {nullptr, 0};
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
