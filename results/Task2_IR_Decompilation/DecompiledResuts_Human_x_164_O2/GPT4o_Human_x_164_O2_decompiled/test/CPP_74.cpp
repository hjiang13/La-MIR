#include <vector>
#include <string>
#include <cstring>

void total_match(std::vector<std::string>& result, const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
    std::string str1, str2;
    size_t index1 = 0, index2 = 0;

    while (index1 < vec1.size() && index2 < vec2.size()) {
        str1 = vec1[index1];
        str2 = vec2[index2];

        if (str1 == str2) {
            result.push_back(str1);
            index1++;
            index2++;
        } else {
            if (str1 < str2) {
                index1++;
            } else {
                index2++;
            }
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
