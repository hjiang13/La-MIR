#include <stdint.h>

typedef struct {
    uint64_t _M_dataplus_size;
    uint64_t _M_dataplus_capacity;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_hider;
    uint64_t _M_string_length;
    char _M_data[];
} basic_string;

int32_t strlen(basic_string *s) {
    return (int32_t)s->_M_string_length;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (strlen("") == 0);
    assert (strlen("x") == 1);
     assert (strlen("asdasnakj") == 9);
}
