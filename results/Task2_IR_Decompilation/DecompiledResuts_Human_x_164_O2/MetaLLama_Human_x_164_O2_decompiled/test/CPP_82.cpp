#include <stdint.h>
#include <stdbool.h>

typedef struct {
    void* _Alloc_hider;
    int64_t _M_string_length;
    union {
        int64_t _M_capacity;
        char _M_data[8];
    } _M_union;
} basic_string;

bool prime_length(basic_string* s) {
    int32_t length = (int32_t)s->_M_string_length;
    if (length < 2) return false;
    if (length < 4) return true;
    int32_t i = 2;
    do {
        int32_t remainder = length % i;
        bool is_prime = (remainder == 0);
        i++;
        int32_t squared = i * i;
        bool is_greater = (squared > length);
        if (is_prime || is_greater) break;
    } while (1);
    bool result = (length % i) != 0;
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (prime_length("Hello") == true);
    assert (prime_length("abcdcba") == true);
    assert (prime_length("kittens") == true);
    assert (prime_length("orange") == false);
    assert (prime_length("wow") == true);
    assert (prime_length("world") == true);
    assert (prime_length("MadaM") == true);
    assert (prime_length("Wow") == true);
    assert (prime_length("") == false);
    assert (prime_length("HI") == true);
    assert (prime_length("go") == true);
    assert (prime_length("gogo") == false);
    assert (prime_length("aaaaaaaaaaaaaaa") == false);
    assert (prime_length("Madam") == true);
    assert (prime_length("M") == false);
    assert (prime_length("0") == false);
}
