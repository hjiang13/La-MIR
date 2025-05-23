```cpp
#include <cstdlib>

extern "C" int abs(int x) {
    return (x < 0) ? -x : x;
}

extern "C" bool iscuberi(int input) {
    bool result = false;
    int temp = 0;
    int counter = 0;

    while (true) {
        int squared = counter * counter;
        int cubed = squared * counter;
        int absInput = abs(input);

        if (cubed <= absInput) {
            int absCounterCubed = abs(cubed);
            if (cubed == absCounterCubed) {
                result = true;
                break;
            }
        } else {
            break;
        }

        counter++;
    }

    return result;
}
```