#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void sorted_list_sum(std::vector<std::string> &result, const std::vector<std::string> &input) {
    result.clear();
    if (input.empty()) {
        return;
    }

    auto it1 = input.begin();
    auto it2 = input.begin() + 1;

    while (it2 != input.end()) {
        if (*it1 == *it2) {
            ++it2;
        } else {
            result.push_back(*it1);
            it1 = it2;
            ++it2;
        }
    }

    result.push_back(*it1);
}

int main() {
    std::vector<std::string> input = {"apple", "apple", "banana", "banana", "cherry"};
    std::vector<std::string> result;
    
    sorted_list_sum(result, input);

    for (const auto &str : result) {
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
    assert (issame(sorted_list_sum({"aa", "a", "aaa"}) , {"aa"}));
    assert (issame(sorted_list_sum({"school", "AI", "asdf", "b"}) , {"AI", "asdf", "school"}));
    assert (issame(sorted_list_sum({"d", "b", "c", "a"}) , {}));
    assert (issame(sorted_list_sum({"d", "dcba", "abcd", "a"}) , {"abcd", "dcba"}));
    assert (issame(sorted_list_sum({"AI", "ai", "au"}) , {"AI", "ai", "au"}));
    assert (issame(sorted_list_sum({"a", "b", "b", "c", "c", "a"}) , {}));
    assert (issame(sorted_list_sum({"aaaa", "bbbb", "dd", "cc"}) , {"cc", "dd", "aaaa", "bbbb"}));
}
