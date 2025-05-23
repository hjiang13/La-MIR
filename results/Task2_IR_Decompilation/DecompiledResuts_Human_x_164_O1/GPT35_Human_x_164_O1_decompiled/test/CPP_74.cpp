```cpp
#include <string>
#include <vector>

void total_match(std::vector<std::string>& output, std::vector<std::string>& input1, std::vector<std::string>& input2) {
    std::string* str1 = &input1[0][0][0][1];
    std::string* str2 = &input1[0][0][0][0];
    long ptr1 = (long)str1;
    long ptr2 = (long)str2;
    long diff = ptr1 - ptr2;
    if (diff == 0) {
        return;
    }

    long max = std::max(diff >> 5, 1);
    for (int i = 0; i < max; i++) {
        long offset = input1[0][0][0][0][i][1];
        int int_offset = static_cast<int>(offset);
        max += int_offset;
    }

    int total1 = 0;
    int total2 = 0;
    for (long i = 0; i < max; i++) {
        long offset = input1[0][0][0][0][i][1];
        int int_offset = static_cast<int>(offset);
        total1 += int_offset;
    }

    for (long i = 0; i < max; i++) {
        long offset = input2[0][0][0][0][i][1];
        int int_offset = static_cast<int>(offset);
        total2 += int_offset;
    }

    if (total1 > total2) {
        output[0][0][0][0] = input1[0][0][0][0];
        output[0][0][0][1] = input1[0][0][0][1];
        output[0][0][0][2] = input2[0][0][0][2];

        std::string* str3 = &input2[0][0][0][0][2];
        output[0][0][0][2] = *str3;

        char* ptr = reinterpret_cast<char*>(&input2);
        memset(ptr, 0, 24);
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
