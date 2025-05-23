```c++
#include <vector>
#include <string>

void all_prefixes(std::vector<std::string>& result, std::string* input) {
    result.clear();
    std::string current_prefix;
    
    for (size_t i = 0; i < input->size(); ++i) {
        current_prefix += (*input)[i];
        result.push_back(current_prefix);
    }
}

int main() {
    std::vector<std::string> prefixes;
    std::string input = "hello";
    
    all_prefixes(prefixes, &input);
    
    for (const auto& prefix : prefixes) {
        std::cout << prefix << std::endl;
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
    assert (issame(all_prefixes(""),{}));
    assert (issame(all_prefixes("asdfgh") ,{"a", "as", "asd", "asdf", "asdfg", "asdfgh"}));
     assert (issame(all_prefixes("WWW") ,{"W", "WW", "WWW"}));
}
