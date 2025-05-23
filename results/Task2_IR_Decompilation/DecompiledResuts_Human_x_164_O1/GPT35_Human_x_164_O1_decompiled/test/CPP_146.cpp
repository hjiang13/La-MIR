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
