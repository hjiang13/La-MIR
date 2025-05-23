#include <vector>
#include <string>

std::vector<std::string> total_match(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
    int total_length1 = 0;
    for (const auto& str : vec1) {
        total_length1 += str.length();
    }

    int total_length2 = 0;
    for (const auto& str : vec2) {
        total_length2 += str.length();
    }

    if (total_length1 > total_length2) {
        return vec2;
    } else {
        return vec1;
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
