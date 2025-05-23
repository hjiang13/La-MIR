#include <vector>
#include <string>

void all_prefixes(std::vector<std::string>& prefixes, const std::string& str) {
    prefixes.clear();
    std::string prefix;
    for (size_t i = 0; i < str.size(); ++i) {
        prefix += str[i];
        prefixes.push_back(prefix);
    }
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
