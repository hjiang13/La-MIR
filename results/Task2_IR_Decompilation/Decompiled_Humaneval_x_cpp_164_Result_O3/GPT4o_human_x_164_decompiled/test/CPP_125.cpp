#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>

void split_words(std::vector<std::string>& result, const std::string& str) {
    size_t len = str.length();
    const char* data = str.c_str();
    size_t start = 0;

    for (size_t i = 0; i < len; ++i) {
        if (data[i] == ' ') {
            if (i > start) {
                result.emplace_back(str.substr(start, i - start));
            }
            start = i + 1;
        }
    }
    if (start < len) {
        result.emplace_back(str.substr(start, len - start));
    }
}

int main() {
    std::vector<std::string> words;
    std::string str = "This is a test string";
    split_words(words, str);

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
