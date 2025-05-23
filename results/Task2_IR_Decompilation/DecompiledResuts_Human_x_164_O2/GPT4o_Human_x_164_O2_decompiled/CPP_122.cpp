```cpp
#include <vector>

extern "C" int add_elements(std::vector<int>* vec, int count) {
    if (count <= 0) return 0;

    int size = vec->size();
    if (count < 8) {
        for (int i = 0; i < count; ++i) {
            (*vec)[i] += 99;
            if ((*vec)[i] >= 199) {
                (*vec)[i] = 0;
            }
        }
        return size;
    }
    
    int result = 0;
    for (int i = 0; i < count; i += 4) {
        int v[4] = {0, 0, 0, 0};
        
        for (int j = 0; j < 4 && (i + j) < count; ++j) {
            v[j] = (*vec)[i + j] + 99;
            if (v[j] >= 199) {
                v[j] = 0;
            }
        }
        
        for (int j = 0; j < 4; ++j) {
            result += v[j];
        }
    }
    
    for (int i = 0; i < count; ++i) {
        (*vec)[i] += 99;
        if ((*vec)[i] >= 199) {
            (*vec)[i] = 0;
        }
    }

    return result;
}
```