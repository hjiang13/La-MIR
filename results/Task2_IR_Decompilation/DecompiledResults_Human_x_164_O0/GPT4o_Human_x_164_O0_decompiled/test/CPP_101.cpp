#include <vector>
#include <string>

void words_string(std::vector<std::string>& vec, const std::string& str) {
    vec.clear();
    auto length = str.length();
    for (size_t i = 0; i < length; ++i) {
        if (str[i] == ' ') {
            continue;
        }
        std::string word;
        while (i < length && str[i] != ' ') {
            word += str[i++];
        }
        if (!word.empty()) {
            vec.push_back(word);
        }
    }
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(words_string("Hi, my name is John") , {"Hi", "my", "name", "is", "John"}));
    assert (issame(words_string("One, two, three, four, five, six") , {"One", "two", "three", "four", "five", "six"}));
    assert (issame(words_string("Hi, my name") , {"Hi", "my", "name"}));
    assert (issame(words_string("One,, two, three, four, five, six,") , {"One", "two", "three", "four", "five", "six"}));
    assert (issame(words_string("") , {}));
    assert (issame(words_string("ahmed     , gamal") , {"ahmed", "gamal"}));
}
