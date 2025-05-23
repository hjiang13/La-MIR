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
    int _M_capacity;

    basic_string(const char* s) {
        _M_data = const_cast<char*>(s);
        _M_string_length = strlen(s);
        _M_capacity = _M_string_length;
    }

    basic_string(const basic_string& other) {
        _M_data = other._M_data;
        _M_string_length = other._M_string_length;
        _M_capacity = other._M_capacity;
    }

    basic_string& operator=(const basic_string& other) {
        _M_data = other._M_data;
        _M_string_length = other._M_string_length;
        _M_capacity = other._M_capacity;
        return *this;
    }

    ~basic_string() {
        delete[] _M_data;
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

    int capacity() const {
        return _M_capacity;
    }

    void clear() {
        _M_string_length = 0;
        _M_capacity = 0;
    }

    void resize(int new_size) {
        if (new_size > _M_capacity) {
            char* new_data = new char[new_size];
            for (int i = 0; i < _M_string_length; i++) {
                new_data[i] = _M_data[i];
            }
            delete[] _M_data;
            _M_data = new_data;
            _M_capacity = new_size;
        }
        _M_string_length = new_size;
    }

    void append(const char* s) {
        int len = strlen(s);
        resize(_M_string_length + len);
        for (int i = 0; i < len; i++) {
            _M_data[_M_string_length + i] = s[i];
        }
    }

    void append(const basic_string& other) {
        append(other._M_data);
    }

    void append(int n, char c) {
        resize(_M_string_length + n);
        for (int i = 0; i < n; i++) {
            _M_data[_M_string_length + i] = c;
        }
    }

    basic_string substr(int pos, int len) const {
        basic_string result;
        result.resize(len);
        for (int i = 0; i < len; i++) {
            result._M_data[i] = _M_data[pos + i];
        }
        return result;
    }

    int compare(const basic_string& other) const {
        int len = _M_string_length < other._M_string_length ? _M_string_length : other._M_string_length;
        for (int i = 0; i < len; i++) {
            if (_M_data[i] != other._M_data[i]) {
                return _M_data[i] - other._M_data[i];
            }
        }
        return _M_string_length - other._M_string_length;
    }

    bool operator==(const basic_string& other) const {
        return _M_string_length == other._M_string_length && _M_data == other._M_data;
    }

    bool operator!=(const basic_string& other) const {
        return !(*this == other);
    }

    bool operator<(const basic_string& other) const {
        return compare(other) < 0;
    }

    bool operator>(const basic_string& other) const {
        return compare(other) > 0;
    }

    bool operator<=(const basic_string& other) const {
        return compare(other) <= 0;
    }

    bool operator>=(const basic_string& other) const {
        return compare(other) >= 0;
    }
};

basic_string filp_case(const basic_string& s) {
    basic_string result;
    result.resize(s.length());
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        } else if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
        result[i] = c;
    }
    return result;
}

int main() {
    basic_string s("Hello, World!");
    basic_string t = filp_case(s);
    cout << t << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should be functionally equivalent.