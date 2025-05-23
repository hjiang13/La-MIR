#include <vector>
#include <string>
#include <iostream>

void words_string(std::vector<std::string>& vec, const std::string& str) {
    vec.clear();
    if (str.empty()) return;

    std::string word;
    size_t start = 0, end = 0;

    while ((end = str.find_first_of(" ", start)) != std::string::npos) {
        word = str.substr(start, end - start);
        vec.push_back(word);
        start = end + 1;
    }
    vec.push_back(str.substr(start));
}

int main() {
    std::vector<std::string> words;
    std::string input = "This is a test string";
    words_string(words, input);

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
    assert (issame(words_string("Hi, my name is John") , {"Hi", "my", "name", "is", "John"}));
    assert (issame(words_string("One, two, three, four, five, six") , {"One", "two", "three", "four", "five", "six"}));
    assert (issame(words_string("Hi, my name") , {"Hi", "my", "name"}));
    assert (issame(words_string("One,, two, three, four, five, six,") , {"One", "two", "three", "four", "five", "six"}));
    assert (issame(words_string("") , {}));
    assert (issame(words_string("ahmed     , gamal") , {"ahmed", "gamal"}));
}
