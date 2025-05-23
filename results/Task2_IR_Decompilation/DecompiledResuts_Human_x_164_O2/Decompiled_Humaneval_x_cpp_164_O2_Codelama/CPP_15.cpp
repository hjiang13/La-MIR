Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <string>

using namespace std;

class basic_string {
public:
    struct _Alloc_hider {
        char *ptr;
    };

    union {
        _Alloc_hider _M_dataplus;
        struct {
            char *ptr;
            int length;
        } data;
    };

    basic_string(char *ptr, int length) {
        _M_dataplus.ptr = ptr;
        data.length = length;
    }

    char *_M_create(int *ptr, int length) {
        return new char[length];
    }

    void _M_append(char *ptr, int length) {
        char *new_ptr = _M_create(ptr, length);
        for (int i = 0; i < length; i++) {
            new_ptr[i] = ptr[i];
        }
        delete[] _M_dataplus.ptr;
        _M_dataplus.ptr = new_ptr;
        data.length += length;
    }

    void _M_replace(int pos, int length, char *ptr) {
        for (int i = 0; i < length; i++) {
            _M_dataplus.ptr[pos + i] = ptr[i];
        }
    }
};

void string_sequence(basic_string &s, int n) {
    basic_string s1(new char[1], 1);
    basic_string s2(new char[1], 1);
    basic_string s3(new char[1], 1);

    s1._M_dataplus.ptr[0] = '0';
    s2._M_dataplus.ptr[0] = '1';
    s3._M_dataplus.ptr[0] = '2';

    s1.data.length = 1;
    s2.data.length = 1;
    s3.data.length = 1;

    for (int i = 0; i < n; i++) {
        s1._M_append(s2._M_dataplus.ptr, s2.data.length);
        s1._M_append(s3._M_dataplus.ptr, s3.data.length);
        s2._M_replace(0, 1, s1._M_dataplus.ptr);
        s3._M_replace(0, 1, s1._M_dataplus.ptr);
    }

    s._M_dataplus.ptr = s1._M_dataplus.ptr;
    s.data.length = s1.data.length;
}

int main() {
    basic_string s;
    string_sequence(s, 10);
    cout << s._M_dataplus.ptr << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same behavior.