#include <vector>
#include <string>
#include <stdexcept>

void filter_by_substring(std::vector<std::string>& result, const std::vector<std::string>& input, const std::string& substring) {
    for (size_t i = 0; i < input.size(); ++i) {
        const std::string& str = input[i];
        if (str.find(substring) != std::string::npos) {
            result.push_back(str);
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
    assert (issame(filter_by_substring({}, "john"),{}));
     assert (issame(filter_by_substring({"xxx", "asd", "xxy", "john doe", "xxxAAA", "xxx"}, "xxx"), {"xxx", "xxxAAA", "xxx"}));
    assert (issame(filter_by_substring({"xxx", "asd", "aaaxxy", "john doe", "xxxAAA", "xxx"}, "xx"),{"xxx", "aaaxxy", "xxxAAA", "xxx"}));
     assert (issame(filter_by_substring({"grunt", "trumpet", "prune", "gruesome"}, "run") ,{"grunt", "prune"}));
}
