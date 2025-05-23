#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void filter_by_prefix(std::vector<std::string>& result, const std::vector<std::string>& input, const std::string& prefix) {
    result.clear();
    size_t prefix_length = prefix.length();
    for (const auto& str : input) {
        if (str.compare(0, prefix_length, prefix) == 0) {
            result.push_back(str);
        }
    }
}

int main() {
    std::vector<std::string> input = {"apple", "banana", "apricot", "cherry", "avocado"};
    std::vector<std::string> filtered;
    std::string prefix = "ap";
    filter_by_prefix(filtered, input, prefix);

    for (const auto& str : filtered) {
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
