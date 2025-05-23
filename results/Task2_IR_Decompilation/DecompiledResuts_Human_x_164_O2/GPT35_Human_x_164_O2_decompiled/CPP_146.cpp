```cpp
#include <iostream>
#include <vector>
#include <string>

int specialFilter(std::vector<int>& vec) {
    std::__cxx11::basic_string str;
    int* ptr1 = &vec[0];
    int* ptr2 = &vec[0];
    int size = vec.size();
    
    for (int i = 0; i < size; i++) {
        if (*ptr1 > 10) {
            char* cstr = new char[size];
            for (int j = size - 1; j >= 0; j--) {
                cstr[j] = ptr1[j] % 2 == 1 ? ptr2[j - 1] % 2 == 1 : 0;
            }
            delete[] cstr;
        }
        ptr1++;
        ptr2++;
    }
    
    return 0;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    specialFilter(vec);
    
    return 0;
}
```