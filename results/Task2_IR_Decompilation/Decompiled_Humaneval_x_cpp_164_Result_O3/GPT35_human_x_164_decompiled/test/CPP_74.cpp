#include <vector>
#include <string>

void total_match(std::vector<std::string>& result, std::vector<std::string>& vec1, std::vector<std::string>& vec2) {
    std::string* str1 = &vec1[0];
    std::string* str2 = &vec1[0];
    
    long long diff = reinterpret_cast<long long>(str1) - reinterpret_cast<long long>(str2);
    
    if (diff == 0) {
        return;
    }
    
    long long diff_shifted = diff >> 5;
    long long max_shifted = std::max(diff_shifted, 1LL);
    long long adjusted_shift = max_shifted - 1;
    long long remainder = max_shifted & 3;
    
    if (remainder < 3) {
        remainder = (max_shifted & -4);
        // continue processing
    }
    
    // more decompiled code here...
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
