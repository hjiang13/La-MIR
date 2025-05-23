#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

std::vector<std::string> filter_by_prefix(const std::vector<std::string>& input, const std::string& prefix) {
    std::vector<std::string> result;
    for (const auto& str : input) {
        if (str.substr(0, prefix.length()) == prefix) {
            result.push_back(str);
        }
    }
    return result;
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
    assert (issame(filter_by_prefix({}, "john") , {}));
    assert (issame(filter_by_prefix({"xxx", "asd", "xxy", "john doe", "xxxAAA", "xxx"}, "xxx") , {"xxx", "xxxAAA", "xxx"}));

}
