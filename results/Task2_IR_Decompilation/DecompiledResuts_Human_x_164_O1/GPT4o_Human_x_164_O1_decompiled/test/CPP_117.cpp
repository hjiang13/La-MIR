#include <vector>
#include <string>
#include <cstring>
#include <iostream>

void select_words(std::vector<std::string>& words, const std::string& input, int length) {
    words.clear();
    if (input.size() > 15) {
        std::string word;
        for (size_t i = 0; i < input.size(); ++i) {
            if (input[i] == ' ') {
                if (!word.empty() && word.size() <= length) {
                    words.push_back(word);
                }
                word.clear();
            } else {
                word += input[i];
            }
        }
        if (!word.empty() && word.size() <= length) {
            words.push_back(word);
        }
    }
}

int main() {
    std::vector<std::string> words;
    std::string input = "This is a sample input string for testing.";
    int length = 10;
    
    select_words(words, input, length);
    
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
    assert (issame(select_words("Mary had a little lamb", 4) , {"little"}   ));
    assert (issame(select_words("Mary had a little lamb", 3) , {"Mary", "lamb"} ));
    assert (issame(select_words("simple white space", 2) , {}     ));
    assert (issame(select_words("Hello world", 4) , {"world"}  ));
    assert (issame(select_words("Uncle sam", 3) , {"Uncle"}));
    assert (issame(select_words("", 4) , {}));
    assert (issame(select_words("a b c d e f", 1) , {"b", "c", "d", "f"}));
}
