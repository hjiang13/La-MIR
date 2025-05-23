#include <vector>
#include <string>
#include <iostream>
#include <cstring>

void select_words(std::vector<std::string>& vec, const std::string& input, int length) {
    // Initialize temporary strings and variables
    std::string temp1, temp2, temp3;
    size_t input_length = input.size();
    
    if (input_length > 15) {
        temp1 = input.substr(0, length);
    } else {
        temp1 = input;
    }
    
    vec.push_back(temp1);
    
    if (length > 0) {
        for (size_t i = 0; i < input_length; ++i) {
            if (input[i] == '\0') break;
            temp2 += input[i];
        }
    }
    
    vec.push_back(temp2);
    
    // Final string processing
    temp3 = input + "_processed";
    vec.push_back(temp3);
}

int main() {
    std::vector<std::string> words;
    std::string input = "aeiouAEIOU";
    int length = input.size();
    
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
