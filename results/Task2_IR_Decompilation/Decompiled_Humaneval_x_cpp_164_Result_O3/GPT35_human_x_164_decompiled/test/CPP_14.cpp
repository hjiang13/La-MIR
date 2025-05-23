#include <vector>
#include <string>

void all_prefixes(std::vector<std::string>& result, const std::string& input) {
    result.clear();
    std::string temp;
    
    for (size_t i = 0; i < input.size(); ++i) {
        temp = "";
        for (size_t j = i; j < input.size(); ++j) {
            temp += input[j];
            result.push_back(temp);
        }
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
