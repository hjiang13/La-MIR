#include <vector>
#include <string>

void total_match(std::vector<std::string> &result, const std::vector<std::string> &vec1, const std::vector<std::string> &vec2) {
    int total_length_vec1 = 0;
    int total_length_vec2 = 0;
    int index1 = 0;

    while (index1 < vec1.size()) {
        total_length_vec1 += vec1[index1].length();
        index1++;
    }

    int index2 = 0;
    
    while (index2 < vec2.size()) {
        total_length_vec2 += vec2[index2].length();
        index2++;
    }

    if (total_length_vec1 > total_length_vec2) {
        result = vec1;
    } else {
        result = vec2;
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
