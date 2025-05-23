#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> sorted_list_sum(const std::vector<std::string>& input) {
    std::vector<std::string> result;
    for (const auto& str : input) {
        if (str.length() % 2 == 0) {
            result.push_back(str);
        }
    }
    std::sort(result.begin(), result.end());
    for (size_t i = 1; i < result.size(); ++i) {
        if (result[i].length() < result[i - 1].length()) {
            std::swap(result[i], result[i - 1]);
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
    assert (issame(sorted_list_sum({"aa", "a", "aaa"}) , {"aa"}));
    assert (issame(sorted_list_sum({"school", "AI", "asdf", "b"}) , {"AI", "asdf", "school"}));
    assert (issame(sorted_list_sum({"d", "b", "c", "a"}) , {}));
    assert (issame(sorted_list_sum({"d", "dcba", "abcd", "a"}) , {"abcd", "dcba"}));
    assert (issame(sorted_list_sum({"AI", "ai", "au"}) , {"AI", "ai", "au"}));
    assert (issame(sorted_list_sum({"a", "b", "b", "c", "c", "a"}) , {}));
    assert (issame(sorted_list_sum({"aaaa", "bbbb", "dd", "cc"}) , {"cc", "dd", "aaaa", "bbbb"}));
}
