#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

void total_match(std::vector<std::string> &result, const std::vector<std::string> &input1, const std::vector<std::string> &input2) {
    size_t count1 = input1.size();
    size_t count2 = input2.size();
    size_t match_count = 0;

    for (size_t i = 0; i < count1; ++i) {
        const std::string &str1 = input1[i];
        const std::string &str2 = (i < count2) ? input2[i] : "";

        if (str1 == str2) {
            match_count = 0;
        } else {
            match_count = std::max(static_cast<size_t>(1), (static_cast<size_t>(str1.size()) >> 5));
        }

        for (size_t j = 0; j < match_count; ++j) {
            if (i < count2) {
                result.push_back(input2[i]);
                result.push_back(str1);
                result.push_back(input1[i]);
            }
        }
    }

    if (result.size() < 2) {
        result.push_back(input1.empty() ? "" : input1[0]);
        result.push_back(input2.empty() ? "" : input2[0]);
    }

    std::memset(&result, 0, sizeof(result));
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
    assert (issame(total_match({}, {}) , {}));
    assert (issame(total_match({"hi", "admin"}, {"hi", "hi"}) , {"hi", "hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hi", "hi", "admin", "project"}) , {"hi", "admin"}));
    assert (issame(total_match({"4"}, {"1", "2", "3", "4", "5"}) , {"4"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "Hi"}) , {"hI", "Hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "hi", "hi"}) , {"hI", "hi", "hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "hi", "hii"}) , {"hi", "admin"}));
    assert (issame(total_match({}, {"this"}) , {}));
    assert (issame(total_match({"this"}, {}) , {}));
}
