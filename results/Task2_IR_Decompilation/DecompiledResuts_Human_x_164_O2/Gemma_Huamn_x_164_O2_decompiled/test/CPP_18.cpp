#include <stdlib.h>
#include <string.h>

struct __cxx11__basic_string {
    struct __cxx11__basic_string__Alloc_hider {
        char* __ptr_;
    } _Alloc_hider;
    long _M_length;
    union {
        long _M_capacity;
        char _M_data[8];
    } _M_data;
};

extern void __gxx_personality_v0(void);
extern void _ZSt24__throw_out_of_range_fmtPKcz(const char*, ...);
extern char *_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(struct __cxx11__basic_string*, long*, long);
extern void* _ZdlPv(void*);
extern int bcmp(const void*, const void*, long);

int _Z14how_many_timesNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES4_(struct __cxx11__basic_string* s1, struct __cxx11__basic_string* s2) {
    long len1 = s1->_M_length;
    if (len1 == 0) {
        return 0;
    }
    long len2 = s2->_M_length;
    struct __cxx11__basic_string temp;
    long i = 0;
    int count = 0;
    while (i < len1) {
        if (i + len2 > len1) {
            break;
        }
        char* ptr1 = s1->_Alloc_hider.__ptr_ + i;
        char* ptr2 = s2->_Alloc_hider.__ptr_;
        int cmp = memcmp(ptr1, ptr2, len2);
        if (cmp == 0) {
            count++;
        }
        i++;
    }
    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (how_many_times("", "x") == 0);
    assert (how_many_times("xyxyxyx", "x") == 4);
     assert (how_many_times("cacacacac", "cac") == 4);
    assert (how_many_times("john doe", "john") == 1);
}
