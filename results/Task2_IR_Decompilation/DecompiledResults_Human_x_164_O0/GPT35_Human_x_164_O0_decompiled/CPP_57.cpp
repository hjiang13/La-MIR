```c
#include <vector>

bool monotonic(std::vector<float>& vec) {
    bool result = true;
    int i = 0;
    int j = 0;
    int k = 1;

    while (k < vec.size()) {
        if (vec[i] > vec[k]) {
            result = false;
            break;
        }
        i = k;
        k++;
    }

    if (result) {
        i = 0;
        j = 0;
        k = 1;
        while (k < vec.size()) {
            if (vec[i] < vec[k]) {
                result = false;
                break;
            }
            i = k;
            k++;
        }
    }

    return result;
}
```