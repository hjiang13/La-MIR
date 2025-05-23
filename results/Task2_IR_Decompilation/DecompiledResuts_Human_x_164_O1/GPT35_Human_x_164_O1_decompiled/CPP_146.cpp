```cpp
#include <vector>
#include <string>
#include <cstdio>

int specialFilter(std::vector<int> &vec) {
    std::__cxx11::basic_string str;
    int sum = 0;
    
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] > 10) {
            char buffer[32];
            snprintf(buffer, 32, "%d", vec[i]);
            int length = strlen(buffer);
            
            int count = 0;
            for (int j = 0; j < length; j++) {
                if (buffer[j] % 2 == 1) {
                    count++;
                }
            }
            
            sum += count;
        }
    }
    
    return sum;
}

int main() {
    std::vector<int> vec = {1, 5, 12, 20, 3};
    int result = specialFilter(vec);
    
    printf("Result: %d\n", result);
    
    return 0;
}
```