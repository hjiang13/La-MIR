#include <stdio.h>
#include <string.h>

typedef struct {
    char* _M_p;
    long long _M_string_length;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    long long _M_string_length;
    long long _M_capacity;
} std_string;

int prime_length(std_string* s) {
    long long length = s->_M_string_length;
    int len = (int)length;
    if (len < 2) return 0;
    if (len < 4) return 1;
    int i = 2;
    while (1) {
        if (len % i == 0) {
            if (i * i > len) return 1;
            else return 0;
        }
        i++;
    }
    return 0;
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
