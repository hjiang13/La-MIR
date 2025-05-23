```C++
#include <string>
#include <cstring>

int how_many_times(std::__cxx11::basic_string<char>* str1, std::__cxx11::basic_string<char>* str2) {
    if (str1->size() == 0) {
        return 0;
    }

    char* copy_str = new char[str1->size() + 1];
    std::memcpy(copy_str, str1->c_str(), str1->size());
    copy_str[str1->size()] = '\0';

    int result = 0;
    for (size_t i = 0; i < str2->size(); i++) {
        if (std::strncmp(copy_str, str2->c_str() + i, str1->size()) == 0) {
            result++;
        }
    }

    delete[] copy_str;
    return result;
}
```