#include <vector>
#include <string>
#include <iostream>
#include <cstdarg>

void split_words(std::vector<std::string>& words, const std::string& str) {
    std::size_t start = 0, end = 0;
    while ((end = str.find(' ', start)) != std::string::npos) {
        if (end > start) {
            words.emplace_back(str.substr(start, end - start));
        }
        start = end + 1;
    }
    if (start < str.length()) {
        words.emplace_back(str.substr(start));
    }
}

int main() {
    std::string input = "This is a test string";
    std::vector<std::string> words;
    split_words(words, input);

    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

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
