```C++
#include <vector>

void _Z9sort_evenSt6vectorIfSaIfEE(std::vector<float>&, std::vector<float> const&);

void _ZNSt6vectorIfSaIfEE17_M_realloc_insertIJRKfEEEvN9__gnu_cxx17__normal_iteratorIPfS1_EEDpOT_(std::vector<float>&, float*, float*);

void _ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_(float*, float*, int64_t);

void _ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_(float*, float*);

void _ZSt20__throw_length_errorPKc(const char*);

void _ZSt17__throw_bad_allocv();

void* _Znwm(int64_t);

void _ZdlPv(void*);

void llvm_memset_p0i8_i64(void*, char, int64_t, bool);

void llvm_lifetime_start_p0i8(int64_t, void*);

void llvm_lifetime_end_p0i8(int64_t, void*);

void llvm_memmove_p0i8_p0i8_i64(void*, void*, int64_t, bool);

int64_t llvm_ctlz_i64(int64_t, bool);

int main() {
    std::vector<float> vec1, vec2;
    _Z9sort_evenSt6vectorIfSaIfEE(vec1, vec2);
    return 0;
}

void _Z9sort_evenSt6vectorIfSaIfEE(std::vector<float>& vec1, std::vector<float> const& vec2) {
    // Implementation here
}

void _ZNSt6vectorIfSaIfEE17_M_realloc_insertIJRKfEEEvN9__gnu_cxx17__normal_iteratorIPfS1_EEDpOT_(std::vector<float>& vec, float* ptr1, float* ptr2) {
    // Implementation here
}

void _ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_(float* ptr1, float* ptr2, int64_t val) {
    // Implementation here
}

void _ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_(float* ptr1, float* ptr2) {
    // Implementation here
}

void _ZSt20__throw_length_errorPKc(const char* str) {
    // Implementation here
}

void _ZSt17__throw_bad_allocv() {
    // Implementation here
}

void* _Znwm(int64_t size) {
    return malloc(size);
}

void _ZdlPv(void* ptr) {
    free(ptr);
}

void llvm_memset_p0i8_i64(void* ptr, char value, int64_t size, bool immarg) {
    // Implementation here
}

void llvm_lifetime_start_p0i8(int64_t size, void* ptr) {
    // Implementation here
}

void llvm_lifetime_end_p0i8(int64_t size, void* ptr) {
    // Implementation here
}

void llvm_memmove_p0i8_p0i8_i64(void* dest, void* src, int64_t size, bool immarg) {
    // Implementation here
}

int64_t llvm_ctlz_i64(int64_t val, bool immarg) {
    // Implementation here
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(sort_even({1, 2, 3}), {1, 2, 3}));
    assert (issame(sort_even({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10}) , {-10, 3, -5, 2, -3, 3, 5, 0, 9, 1, 123}));
    assert (issame(sort_even({5, 8, -12, 4, 23, 2, 3, 11, 12, -10}) , {-12, 8, 3, 4, 5, 2, 12, 11, 23, -10}));
}
