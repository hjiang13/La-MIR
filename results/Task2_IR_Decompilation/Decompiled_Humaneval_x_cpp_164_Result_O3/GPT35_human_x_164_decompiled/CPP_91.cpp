```c++
#include <string>

int is_bored(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>* str) {
    if (str->size() == 0) {
        return 0;
    }

    int count = 0;
    int sum = 0;
    int space_count = 0;

    for (unsigned long i = 0; i < str->size(); ++i) {
        char c = (*str)[i];
        if (c == ' ') {
            sum += space_count;
            space_count = 0;
        } else {
            space_count = 1;
        }
    }

    return sum;
}
```