#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>

int specialFilter(std::vector<int>& vec) {
    std::string str;
    int result = 0;
    int* ptr1 = vec.data();
    int* ptr2 = vec.data(); // Assuming these two pointers are meant to be compared
    
    if (ptr1 == ptr2) {
        return 0;
    }

    for (size_t i = 0; i < vec.size(); ++i) {
        int value = vec[i];
        if (value > 10) {
            char buffer[32];
            vsnprintf(buffer, sizeof(buffer), "%d", value);
            str.append(buffer);
            if (str.back() % 2 == 1) {
                result++;
            }
        }
    }

    return result;
}

extern "C" {
    void __gxx_personality_v0();
}

int main() {
    std::vector<int> myVector = {1, 20, 3, 42, 5};
    int count = specialFilter(myVector);
    printf("Count: %d\n", count);
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
