#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void select_words(std::vector<std::string>& vec, const std::string& str, int size) {
    if (size < 0) throw std::length_error("size must be non-negative");
    
    size_t len = str.size();
    if (len > 15) {
        vec.resize(len);
        std::memcpy(vec.data(), str.data(), len);
        vec[len] = '\0';
    } else {
        vec.resize(1);
        vec[0] = str;
    }
}

int main() {
    std::vector<std::string> words;
    std::string input = "example";
    select_words(words, input, input.size());
    
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
