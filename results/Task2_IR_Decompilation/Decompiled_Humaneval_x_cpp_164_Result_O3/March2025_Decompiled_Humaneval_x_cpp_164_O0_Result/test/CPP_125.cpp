#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

std::vector<std::string> split_words(const std::string &input) {
    std::vector<std::string> result;
    std::string current_word;
    for (char c : input) {
        if (c == ' ') {
            if (!current_word.empty()) {
                result.push_back(current_word);
                current_word.clear();
            }
        } else {
            current_word += c;
        }
    }
    if (!current_word.empty()) {
        result.push_back(current_word);
    }
    return result;
}

int main() {
    std::string input = "This is a test string";
    std::vector<std::string> words = split_words(input);
    for (const auto &word : words) {
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
