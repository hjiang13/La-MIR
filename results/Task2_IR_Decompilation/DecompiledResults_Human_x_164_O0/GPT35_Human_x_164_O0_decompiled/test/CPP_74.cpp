#include <vector>
#include <string>

void total_match(std::vector<std::string> &result, std::vector<std::string> &vec1, std::vector<std::string> &vec2) {
    for (size_t i = 0; i < vec1.size(); i++) {
        std::string str = vec1[i];
        result.push_back(str);
    }
    for (size_t i = 0; i < vec2.size(); i++) {
        std::string str = vec2[i];
        result.push_back(str);
    }
}

int main() {
    std::vector<std::string> vec1 = {"Hello", "World"};
    std::vector<std::string> vec2 = {"C++", "Programming"};
    std::vector<std::string> result;

    total_match(result, vec1, vec2);

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
