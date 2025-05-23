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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (specialFilter({5, -2, 1, -5}) == 0  );
    assert (specialFilter({15, -73, 14, -15}) == 1);
    assert (specialFilter({33, -2, -3, 45, 21, 109}) == 2);
    assert (specialFilter({43, -12, 93, 125, 121, 109}) == 4);
    assert (specialFilter({71, -2, -33, 75, 21, 19}) == 3);
    assert (specialFilter({1}) == 0              );
    assert (specialFilter({}) == 0                   );
}
