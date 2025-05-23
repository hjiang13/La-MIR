#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    union {
        struct {
            char* _M_dataplus;
            size_t _M_string_length;
        };
        char* _M_data;
    };
    size_t _M_allocated_capacity;
} basic_string;

void encrypt(basic_string* dst, const basic_string* src) {
    dst->_M_dataplus = (char*)malloc(sizeof(char) * 32);
    dst->_M_string_length = 0;
    dst->_M_allocated_capacity = 32;

    size_t src_len = src->_M_string_length;
    if (src_len == 0) {
        return;
    }
    
    char* src_data = src->_M_dataplus;
    for (size_t i = 0; i < src_len; i++) {
        char c = src_data[i];
        int32_t shifted = c - 93;
        int32_t result = shifted % 26 + 97;
        dst->_M_dataplus[i] = (char)result;
    }
    dst->_M_string_length = src_len;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (encrypt("hi") == "lm");
    assert (encrypt("asdfghjkl") == "ewhjklnop");
    assert (encrypt("gf") == "kj");
    assert (encrypt("et") == "ix");
    assert (encrypt("faewfawefaewg")=="jeiajeaijeiak");
    assert (encrypt("hellomyfriend")=="lippsqcjvmirh");
    assert (encrypt("dxzdlmnilfuhmilufhlihufnmlimnufhlimnufhfucufh")=="hbdhpqrmpjylqmpyjlpmlyjrqpmqryjlpmqryjljygyjl");
    assert (encrypt("a")=="e");
}
