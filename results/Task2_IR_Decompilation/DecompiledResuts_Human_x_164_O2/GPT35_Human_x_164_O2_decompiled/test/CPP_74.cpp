```cpp
#include <vector>
#include <string>

void total_match(std::vector<std::string>& result, std::vector<std::string>& input1, std::vector<std::string>& input2) {
    std::string* str1 = input1[0][0][0][1];
    std::string* str2 = input1[0][0][0][0];
    long long int diff = (long long int)str1 - (long long int)str2;
    if (diff == 0) {
        return;
    }
    long long int num_iterations = diff >> 5;
    num_iterations = std::max(num_iterations, 1LL);
    num_iterations--;
    int remainder = num_iterations & 3;
    bool less_than_3 = num_iterations < 3;
    if (less_than_3) {
        remainder = num_iterations & -4;
    }
    for (int i = 0; i < remainder; i++) {
        int offset = 0;
        for (int j = 0; j < 4; j++) {
            std::string* current_str = str2 + i;
            offset += *(long long int*)(current_str + 1);
        }
        result[0][0][0][0] += offset;
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
