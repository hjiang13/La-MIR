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
