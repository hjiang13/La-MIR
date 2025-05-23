#include <vector>
#include <string>
#include <stdexcept>

void split_words(std::vector<std::string>& words, const std::string& str) {
    size_t start = 0;
    size_t end = 0;
    while (end != std::string::npos) {
        end = str.find(' ', start);
        std::string word = str.substr(start, end - start);
        if (!word.empty()) {
            words.push_back(word);
        }
        start = end + 1;
    }
}

int main() {
    std::vector<std::string> words;
    std::string str = "This is a sample string";
    split_words(words, str);
    return 0;
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
    assert (issame(split_words("Hello world!") , {"Hello","world!"}));
    assert (issame(split_words("Hello,world!") , {"Hello","world!"}));
    assert (issame(split_words("Hello world,!") , {"Hello","world,!"}));
    assert (issame(split_words("Hello,Hello,world !") , {"Hello,Hello,world","!"}));
    assert (issame(split_words("abcdef") , {"3"}));
    assert (issame(split_words("aaabb") , {"2"}));
    assert (issame(split_words("aaaBb") , {"1"}));
    assert (issame(split_words("") ,{"0"}));
}
