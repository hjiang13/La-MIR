```cpp
#include <vector>
#include <string>
#include <cstring>

std::vector<std::string> filter_by_prefix(std::vector<std::string>& input, std::string& prefix) {
    std::vector<std::string> result;
    
    for (const std::string& str : input) {
        if (str.substr(0, prefix.length()) == prefix) {
            result.push_back(str);
        }
    }
    
    return result;
}

int main() {
    std::vector<std::string> input = {"hello", "world", "how", "are", "you"};
    std::string prefix = "h";
    
    std::vector<std::string> filtered = filter_by_prefix(input, prefix);
    
    for (const std::string& str : filtered) {
        std::cout << str << std::endl;
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
    assert (issame(filter_by_prefix({}, "john") , {}));
    assert (issame(filter_by_prefix({"xxx", "asd", "xxy", "john doe", "xxxAAA", "xxx"}, "xxx") , {"xxx", "xxxAAA", "xxx"}));

}
