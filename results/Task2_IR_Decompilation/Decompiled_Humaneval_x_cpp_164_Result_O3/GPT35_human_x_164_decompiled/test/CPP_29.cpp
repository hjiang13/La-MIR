#include <vector>
#include <string>

void filter_by_prefix(std::vector<std::string>& result, const std::vector<std::string>& input, const std::string& prefix) {
    result.clear();

    for (const std::string& str : input) {
        if (str.substr(0, prefix.size()) == prefix) {
            result.push_back(str);
        }
    }
}

int bcmp(const void* s1, const void* s2, size_t n);

void _ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_realloc_insertIJRKS5_EEEvN9__gnu_cxx17__normal_iteratorIPS5_S7_EEDpOT_(std::vector<std::string>& vec, std::string* pos, std::string* str) {
    size_t offset = std::distance(vec.begin(), pos);
    vec.insert(pos, *str);
}

void _ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev(std::vector<std::string>& vec) {
    for (std::string& str : vec) {
        delete &str;
    }
}

void __clang_call_terminate(void* ptr) {
    __cxa_begin_catch(ptr);
    std::terminate();
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
    assert (issame(filter_by_prefix({}, "john") , {}));
    assert (issame(filter_by_prefix({"xxx", "asd", "xxy", "john doe", "xxxAAA", "xxx"}, "xxx") , {"xxx", "xxxAAA", "xxx"}));

}
