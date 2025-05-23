#include <vector>
#include <string>
#include <algorithm>

void sorted_list_sum(std::vector<std::string>& result, const std::vector<std::string>& input) {
    result.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i].length() % 2 == 0) {
            result.push_back(input[i]);
        }
    }
    std::sort(result.begin(), result.end());
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
