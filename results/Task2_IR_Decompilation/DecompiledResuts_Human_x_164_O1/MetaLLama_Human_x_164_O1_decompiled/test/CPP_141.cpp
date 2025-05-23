#include <stdlib.h>
#include <string.h>

typedef struct {
    char* _M_p;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    long _M_string_length;
    char _M_local_buf[16];
} basic_string;

typedef struct {
    char _M_x;
} allocator;

extern void __throw_out_of_range_fmt(const char*, ...);
extern int __gxx_personality_v0(...);
extern void _ZdlPv(void*);
extern int _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7compareEPKc(basic_string*, const char*);

void _Z15file_name_checkNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(basic_string* noalias sret, basic_string* nocapture readonly str) {
    basic_string tmp;
    allocator alloc;

    if (str->_M_string_length < 5) {
        sret->_M_dataplus._M_p = "No";
        sret->_M_string_length = 2;
        return;
    }

    switch (str->_M_dataplus._M_p[0]) {
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 123:
        case 124:
        case 125:
        case 126:
        case 127:
        {
            sret->_M_dataplus._M_p = "No";
            sret->_M_string_length = 2;
            return;
        }
        default:
            break;
    }

    tmp._M_dataplus._M_p = &str->_M_dataplus._M_p[str->_M_string_length - 4];

    if (str->_M_string_length < 4) {
        __throw_out_of_range_fmt("%s: __pos (which is %zu) > this->size() (which is %zu)", "_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6substrEmm", str->_M_string_length - 4, str->_M_string_length);
    }

    if (strcmp(tmp._M_dataplus._M_p, ".txt") == 0 || strcmp(tmp._M_dataplus._M_p, ".exe") == 0 || strcmp(tmp._M_dataplus._M_p, ".dll") == 0) {
        sret->_M_dataplus._M_p = "No";
        sret->_M_string_length = 2;
        return;
    }

    int dot_cnt = 0;
    int digit_cnt = 0;

    for (long i = 0; i < str->_M_string_length; i++) {
        char c = str->_M_dataplus._M_p[i];
        if (c >= '0' && c <= '9') {
            digit_cnt++;
        } else if (c == '.') {
            dot_cnt++;
        }
    }

    if (digit_cnt > 3 || dot_cnt != 1) {
        sret->_M_dataplus._M_p = "No";
        sret->_M_string_length = 2;
    } else {
        sret->_M_dataplus._M_p = "Yes";
        sret->_M_string_length = 3;
    }

    return;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (file_name_check("example.txt") == "Yes");
    assert (file_name_check("1example.dll") == "No");
    assert (file_name_check("s1sdf3.asd") == "No");
    assert (file_name_check("K.dll") == "Yes");
    assert (file_name_check("MY16FILE3.exe") == "Yes");
    assert (file_name_check("His12FILE94.exe") == "No");
    assert (file_name_check("_Y.txt") == "No");
    assert (file_name_check("?aREYA.exe") == "No");
    assert (file_name_check("/this_is_valid.dll") == "No");
    assert (file_name_check("this_is_valid.wow") == "No");
    assert (file_name_check("this_is_valid.txt") == "Yes");
    assert (file_name_check("this_is_valid.txtexe") == "No");
    assert (file_name_check("#this2_i4s_5valid.ten") == "No");
    assert (file_name_check("@this1_is6_valid.exe") == "No");
    assert (file_name_check("this_is_12valid.6exe4.txt") == "No");
    assert (file_name_check("all.exe.txt") == "No");
    assert (file_name_check("I563_No.exe") == "Yes");
    assert (file_name_check("Is3youfault.txt") == "Yes");
    assert (file_name_check("no_one#knows.dll") == "Yes");
    assert (file_name_check("1I563_Yes3.exe") == "No");
    assert (file_name_check("I563_Yes3.txtt") == "No");
    assert (file_name_check("final..txt") == "No");
    assert (file_name_check("final132") == "No");
    assert (file_name_check("_f4indsartal132.") == "No");
    assert (file_name_check(".txt") == "No");
    assert (file_name_check("s.") == "No");
}
