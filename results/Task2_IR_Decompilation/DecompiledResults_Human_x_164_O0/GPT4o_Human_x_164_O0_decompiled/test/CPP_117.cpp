#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void select_words(std::vector<std::string>& output, const std::string& input, int length) {
    const char* vowels = "aeiouAEIOU";
    std::string buffer;

    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == ' ') {
            if (!buffer.empty() && buffer.length() == length) {
                output.push_back(buffer);
            }
            buffer.clear();
        } else {
            buffer += input[i];
        }
    }

    if (!buffer.empty() && buffer.length() == length) {
        output.push_back(buffer);
    }
}

int main() {
    std::vector<std::string> words;
    std::string input = "This is a sample input string";
    select_words(words, input, 2);
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
