#include <vector>
#include <string>
#include <stdexcept>

std::vector<std::string> all_prefixes(const std::string& input) {
    std::vector<std::string> result;
    std::string prefix;
    for (size_t i = 0; i < input.length(); ++i) {
        prefix += input[i];
        result.push_back(prefix);
    }
    return result;
}

int main() {
    std::string input = "example";
    std::vector<std::string> prefixes = all_prefixes(input);
    for (const auto& prefix : prefixes) {
        // Do something with each prefix
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
