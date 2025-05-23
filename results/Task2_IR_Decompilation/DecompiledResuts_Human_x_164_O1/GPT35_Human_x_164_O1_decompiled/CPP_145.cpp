```cpp
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

void order_by_points(std::vector<int>& result, std::vector<int>& input) {
    std::vector<int> temp;
    std::__cxx11::basic_string<char> str;
    int count = 0;

    for (int i = 0; i < input.size(); i++) {
        int num = std::abs(input[i]);
        char cstr[16];
        std::snprintf(cstr, sizeof(cstr), "%d", num);
        std::__gnu_cxx::__to_xstring(&str, std::vsnprintf, sizeof(cstr), cstr);
        int val = 0;
        for (int j = 0; j < str.size(); j++) {
            if (std::isdigit(str[j])) {
                val = val * 10 + (str[j] - '0');
            }
        }
        temp.push_back(val);
    }

    result = temp;
}

void __gnu_cxx::__to_xstring(std::__cxx11::basic_string<char>* str, int (*vsnprintf)(char*, size_t, const char*, va_list), size_t size, char* format, ...) {
    va_list args;
    va_start(args, format);
    int len = vsnprintf(format, size, args);
    va_end(args);

    str->_M_create(len, 0);
    if (len) {
        if (len == 1) {
            str->_M_dataplus._M_p = format;
        } else {
            std::memcpy(str->_M_dataplus._M_p, format, len);
        }
    }
}

void std::vector<int>::_M_realloc_insert(std::__gnu_cxx::__normal_iterator<int*, std::vector<int>> it, int* val) {
    int* start = it.base();
    int* end = this->_M_impl._M_start;
    int size = (end - start) / sizeof(int);
    int new_size = size + 1;
    
    if (size == 0) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    if (new_size > size) {
        if (new_size > 2305843009213693951) {
            throw std::bad_alloc();
        }
        
        int* temp = new int[new_size];
        std::copy(start, val, temp);
        std::copy(val, end, temp + 1);
        
        if (this->_M_impl._M_start != nullptr) {
            delete[] this->_M_impl._M_start;
        }
        
        this->_M_impl._M_start = temp;
        this->_M_impl._M_finish = temp + new_size;
        this->_M_impl._M_end_of_storage = temp + new_size;
    }
}
```