Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <string>

using namespace std;

class basic_string {
public:
    struct _Alloc_hider {
        char* _M_p;
    };
    union {
        char* _M_data;
        char _M_local_data[8];
    };
    _Alloc_hider _M_dataplus;
    int _M_string_length;

    basic_string(const char* s) {
        _M_data = _M_local_data;
        _M_string_length = strlen(s);
        strcpy(_M_data, s);
    }

    basic_string(const basic_string& other) {
        _M_data = _M_local_data;
        _M_string_length = other._M_string_length;
        strcpy(_M_data, other._M_data);
    }

    ~basic_string() {
        if (_M_data != _M_local_data) {
            delete[] _M_data;
        }
    }

    basic_string& operator=(const basic_string& other) {
        if (this != &other) {
            if (_M_data != _M_local_data) {
                delete[] _M_data;
            }
            _M_data = _M_local_data;
            _M_string_length = other._M_string_length;
            strcpy(_M_data, other._M_data);
        }
        return *this;
    }

    char* c_str() {
        return _M_data;
    }

    int length() {
        return _M_string_length;
    }

    void substr(int pos, int len) {
        if (pos < 0 || pos >= _M_string_length) {
            return;
        }
        if (len < 0 || len > _M_string_length - pos) {
            len = _M_string_length - pos;
        }
        _M_data = _M_local_data;
        _M_string_length = len;
        strncpy(_M_data, _M_data + pos, len);
    }
};

void file_name_check(basic_string& s) {
    basic_string s1 = s;
    if (s1.length() < 5) {
        s = "No";
        return;
    }
    s1.substr(0, 3);
    if (s1 == "Yes") {
        s = "Yes";
        return;
    }
    s1.substr(s1.length() - 4, 4);
    if (s1 == ".txt" || s1 == ".exe" || s1 == ".dll") {
        s = "Yes";
        return;
    }
    s = "No";
}

int main() {
    basic_string s = "Hello.txt";
    file_name_check(s);
    cout << s.c_str() << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same behavior.