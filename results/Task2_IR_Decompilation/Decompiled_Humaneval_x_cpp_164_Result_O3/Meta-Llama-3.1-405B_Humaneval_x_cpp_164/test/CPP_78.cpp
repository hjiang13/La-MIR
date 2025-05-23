#include <string.h>

typedef struct {
    char* _M_p;
    unsigned long _M_string_length;
    unsigned long _M_capacity;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    unsigned long _M_string_length;
    char _M_local_buf[8];
} basic_string;

int hex_key(basic_string* input) {
    basic_string key;
    char* key_ptr = (char*)&key._M_local_buf;
    memcpy(key_ptr, "2357BD", 6);
    key._M_string_length = 6;
    key_ptr[6] = 0;

    if (input->_M_string_length == 0) {
        return 0;
    }

    char* input_ptr = input->_M_dataplus._M_p;
    unsigned long i = 0;
    unsigned int match_count = 0;
    while (i < input->_M_string_length) {
        char c = input_ptr[i];
        if (c == key_ptr[0] || c == key_ptr[1] || c == key_ptr[2] || c == key_ptr[3] || c == key_ptr[4] || c == key_ptr[5]) {
            match_count++;
        }
        i++;
    }
    return match_count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (hex_key("AB") == 1      );
    assert (hex_key("1077E") == 2 );
    assert (hex_key("ABED1A33") == 4     );
    assert (hex_key("2020") == 2 );
    assert (hex_key("123456789ABCDEF0") == 6      );
    assert (hex_key("112233445566778899AABBCCDDEEFF00") == 12 );
    assert (hex_key("") == 0);
}
