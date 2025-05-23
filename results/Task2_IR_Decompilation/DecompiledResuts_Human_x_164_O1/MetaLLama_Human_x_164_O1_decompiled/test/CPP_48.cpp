#include <string.h>

typedef struct {
    char* _M_p;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    unsigned long long _M_string_length;
    char _M_local_buf[16];
} basic_string;

int bcmp(const char* s1, const char* s2, unsigned long long n) {
    unsigned long long i;
    for (i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

void* _ZdlPv(void* p) {
    free(p);
    return p;
}

int _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(basic_string* this, unsigned long long* p, unsigned long long n) {
    this->_M_dataplus._M_p = malloc(n);
    this->_M_string_length = n;
    return this->_M_dataplus._M_p;
}

int is_palindrome(basic_string* s) {
    unsigned long long length = s->_M_string_length;
    char* data = s->_M_dataplus._M_p;
    char* reversed_data = malloc(length);
    unsigned long long i;
    for (i = 0; i < length; i++) {
        reversed_data[i] = data[length - i - 1];
    }
    int result = bcmp(data, reversed_data, length);
    free(reversed_data);
    return result == 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_palindrome("") == true);
    assert (is_palindrome("aba") == true);
    assert (is_palindrome("aaaaa") == true);
    assert (is_palindrome("zbcd") == false);
    assert (is_palindrome("xywyx") == true);
    assert (is_palindrome("xywyz") == false);
    assert (is_palindrome("xywzx") == false);
}
