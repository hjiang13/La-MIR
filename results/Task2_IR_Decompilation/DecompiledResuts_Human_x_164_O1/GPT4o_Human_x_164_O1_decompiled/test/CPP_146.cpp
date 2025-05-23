#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

extern "C" {
    void __gxx_personality_v0();
}

int specialFilter(std::vector<int> &vec) {
    std::string result;
    int returnValue = 0;

    int* firstPtr = vec.data();
    int* secondPtr = vec.data();

    if (firstPtr == secondPtr) {
        return returnValue;
    }

    for (size_t i = 0; i < vec.size(); ++i) {
        int value = vec[i];
        if (value > 10) {
            char buffer[32];
            int length = snprintf(buffer, sizeof(buffer), "%d", value);
            result = buffer;

            if (buffer[length - 1] == '\0') {
                returnValue++;
            }
        }
    }

    return returnValue;
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
