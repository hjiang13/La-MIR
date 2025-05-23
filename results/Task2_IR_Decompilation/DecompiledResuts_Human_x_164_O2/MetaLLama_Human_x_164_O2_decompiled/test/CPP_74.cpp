#include <string.h>

void total_match(std::vector<std::string>& result, std::vector<std::string>& vec1, std::vector<std::string>& vec2) {
    size_t vec1_size = vec1.size();
    size_t vec2_size = vec2.size();

    if (vec1_size == 0) {
        result = vec2;
        return;
    }

    if (vec2_size == 0) {
        result = vec1;
        return;
    }

    size_t vec1_total_length = 0;
    for (size_t i = 0; i < vec1_size; i++) {
        vec1_total_length += vec1[i].length();
    }

    size_t vec2_total_length = 0;
    for (size_t i = 0; i < vec2_size; i++) {
        vec2_total_length += vec2[i].length();
    }

    if (vec1_total_length > vec2_total_length) {
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
