#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* _M_p;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    unsigned long long _M_string_length;
    union {
        unsigned long long _M_capacity;
        char _M_data;
    } _M_string_data;
} std_string;

void _Z9filp_caseNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(std_string* this, const std_string* other) {
    if (other->_M_string_length == 0) return;

    this->_M_string_length = 0;
    this->_M_string_data._M_data = 0;

    char* p = other->_M_dataplus._M_p;
    for (unsigned long long i = 0; i < other->_M_string_length; i++) {
        char c = p[i];
        if (c < 97) {
            if (c < 65) {
                c = c;
            } else {
                c = c - 65 + 97;
            }
        } else {
            c = c - 32;
        }

        std_string temp;
        temp._M_dataplus._M_p = (char*)malloc(32);
        temp._M_string_length = 0;
        temp._M_string_data._M_capacity = 0;

        if (this->_M_string_length > 15) {
            temp._M_dataplus._M_p = (char*)malloc(this->_M_string_length);
        }

        if (this->_M_string_length == 1) {
            *temp._M_dataplus._M_p = *this->_M_dataplus._M_p;
        } else if (this->_M_string_length > 1) {
            memcpy(temp._M_dataplus._M_p, this->_M_dataplus._M_p, this->_M_string_length);
        }

        temp._M_string_length = this->_M_string_length;
        *(temp._M_dataplus._M_p + temp._M_string_length) = 0;

        this->_M_string_length = temp._M_string_length + 1;
        this->_M_dataplus._M_p = (char*)malloc(this->_M_string_length);

        if (this->_M_string_length > 1) {
            memcpy(this->_M_dataplus._M_p, temp._M_dataplus._M_p, temp._M_string_length);
        }

        *(this->_M_dataplus._M_p + this->_M_string_length - 1) = c;
        *(this->_M_dataplus._M_p + this->_M_string_length) = 0;

        if (temp._M_dataplus._M_p != temp._M_string_data._M_data) {
            free(temp._M_dataplus._M_p);
        }
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}
