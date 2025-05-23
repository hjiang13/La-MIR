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
        _Alloc_hider _M_dataplus;
    };
    int _M_string_length;

    basic_string() {
        _M_data = nullptr;
        _M_string_length = 0;
    }

    basic_string(const basic_string& other) {
        _M_data = other._M_data;
        _M_string_length = other._M_string_length;
    }

    ~basic_string() {
        delete[] _M_data;
    }

    basic_string& operator=(const basic_string& other) {
        if (this != &other) {
            delete[] _M_data;
            _M_data = other._M_data;
            _M_string_length = other._M_string_length;
        }
        return *this;
    }

    char& operator[](int index) {
        return _M_data[index];
    }

    const char& operator[](int index) const {
        return _M_data[index];
    }

    int length() const {
        return _M_string_length;
    }
};

class vector {
public:
    struct _Vector_base {
        basic_string* _M_impl;
    };
    _Vector_base _M_base;

    vector() {
        _M_base._M_impl = nullptr;
    }

    vector(const vector& other) {
        _M_base._M_impl = other._M_base._M_impl;
    }

    ~vector() {
        delete[] _M_base._M_impl;
    }

    vector& operator=(const vector& other) {
        if (this != &other) {
            delete[] _M_base._M_impl;
            _M_base._M_impl = other._M_base._M_impl;
        }
        return *this;
    }

    basic_string& operator[](int index) {
        return _M_base._M_impl[index];
    }

    const basic_string& operator[](int index) const {
        return _M_base._M_impl[index];
    }

    int size() const {
        return _M_base._M_impl->length();
    }
};

basic_string longest(vector v) {
    basic_string longest;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].length() > longest.length()) {
            longest = v[i];
        }
    }
    return longest;
}

int main() {
    vector v;
    v.push_back("hello");
    v.push_back("world");
    v.push_back("this");
    v.push_back("is");
    v.push_back("a");
    v.push_back("test");
    cout << longest(v) << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should be functionally equivalent.