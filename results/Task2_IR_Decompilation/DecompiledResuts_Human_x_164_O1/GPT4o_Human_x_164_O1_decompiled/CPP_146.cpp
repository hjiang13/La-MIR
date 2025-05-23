```cpp
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
```