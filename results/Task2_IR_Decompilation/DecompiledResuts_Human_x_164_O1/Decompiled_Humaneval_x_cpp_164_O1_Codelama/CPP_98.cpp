Sure, here's the decompiled C++ source code for the provided IR code:

#include<stdio.h>
#include<string>
using namespace std;

class basic_string {
public:
    struct _Alloc_hider {
        char* _M_p;
    };
    union {
        _Alloc_hider _M_dataplus;
        char _M_local_data[8];
    };
    basic_string() {
        _M_dataplus._M_p = _M_local_data;
        _M_local_data[0] = 0;
        _M_local_data[1] = 0;
    }
    basic_string(const char* s) {
        _M_dataplus._M_p = _M_local_data;
        _M_local_data[0] = 0;
        _M_local_data[1] = 0;
        while (*s) {
            _M_local_data[0]++;
            _M_local_data[1]++;
            s++;
        }
    }
    ~basic_string() {
        if (_M_dataplus._M_p != _M_local_data) {
            delete[] _M_dataplus._M_p;
        }
    }
    basic_string(const basic_string& other) {
        _M_dataplus._M_p = _M_local_data;
        _M_local_data[0] = 0;
        _M_local_data[1] = 0;
        for (int i = 0; i < other._M_local_data[0]; i++) {
            _M_local_data[0]++;
            _M_local_data[1]++;
            _M_local_data[i] = other._M_local_data[i];
        }
    }
    basic_string& operator=(const basic_string& other) {
        if (this != &other) {
            if (_M_dataplus._M_p != _M_local_data) {
                delete[] _M_dataplus._M_p;
            }
            _M_dataplus._M_p = _M_local_data;
            _M_local_data[0] = 0;
            _M_local_data[1] = 0;
            for (int i = 0; i < other._M_local_data[0]; i++) {
                _M_local_data[0]++;
                _M_local_data[1]++;
                _M_local_data[i] = other._M_local_data[i];
            }
        }
        return *this;
    }
    char& operator[](int index) {
        return _M_local_data[index];
    }
    const char& operator[](int index) const {
        return _M_local_data[index];
    }
    int length() const {
        return _M_local_data[0];
    }
    char* c_str() {
        return _M_local_data;
    }
};

int count_upper(basic_string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            count++;
        }
    }
    return count;
}

int main() {
    basic_string str("AEIOU");
    int count = count_upper(str);
    printf("Number of uppercase letters: %d\n", count);
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during compilation. However, the decompiled code should be functionally equivalent to the original source code.