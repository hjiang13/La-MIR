#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>

void sorted_list_sum(std::vector<std::string>& result, const std::vector<std::string>& input) {
    result.clear();
    if (input.empty()) return;

    std::string first, second;
    for (size_t i = 0; i < input.size(); ++i) {
        if (i % 2 == 0) {
            first = input[i];
        } else {
            second = input[i];
            if (first == second) continue;
            result.push_back(first + second);
        }
    }
}

int main() {
    std::vector<std::string> input = {"apple", "banana", "apple", "orange"};
    std::vector<std::string> result;
    sorted_list_sum(result, input);
    
    for (const std::string& str : result) {
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
