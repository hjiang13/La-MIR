```cpp
#include <vector>
#include <string>
#include <cstdio>

int specialFilter(std::vector<int>& vec) {
    std::__cxx11::basic_string str;
    int* ptr1 = &vec[0];
    int* ptr2 = &vec[0];
    
    if (ptr1 == ptr2) {
        return 0;
    } else {
        int sum = 0;
        for (size_t i = 0; i < vec.size(); ++i) {
            if (vec[i] > 10) {
                char buffer[32];
                snprintf(buffer, 32, "%d", vec[i]);
                char lastChar = buffer[strlen(buffer) - 1];
                if ((lastChar % 2) == 1) {
                    sum++;
                }
            }
        }
        return sum;
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 15, 16, 17, 25};
    int result = specialFilter(vec);
    printf("Number of elements greater than 10 with odd last digit: %d\n", result);
    
    return 0;
}
```