```c++
#include <iostream>
#include <vector>
#include <string>

void even_odd_count(std::vector<int>& vec, int num) {
    std::__cxx11::basic_string str;
    char buffer[16];

    snprintf(buffer, 16, "%d", abs(num));

    str = std::__gnu_cxx::__to_xstring(str, vsnprintf, 16, buffer, ...);

    int size = str.size();
    for (int i = 0; i < size; i++) {
        char ch = str[i];
        if (i % 2 == 0) {
            // even
            // do something
        } else {
            // odd
            // do something
        }
    }

    // memset
    vec.clear();
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);

    // dynamic memory allocation
    char* ptr = new char[8];

    for (int i = 0; i < size; i++) {
        char ch = str[i];
        if (ch % 2 == 1) {
            vec[1] += 1;
        } else {
            vec[0] += 1;
        }
    }

    delete[] ptr;
}
```