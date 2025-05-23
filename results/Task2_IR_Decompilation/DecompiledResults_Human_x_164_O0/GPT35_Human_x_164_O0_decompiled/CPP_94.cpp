```cpp
#include <vector>
#include <string>

int skjkasdkd(std::vector<int>* vec) {
    int result = 0;
    int maxVal = 0;
    int size = vec->size();
    
    for (int i = 0; i < size; i++) {
        int value = (*vec)[i];
        if (value > maxVal) {
            result = 1;
            maxVal = value;
        }
    }
    
    return result;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    skjkasdkd(&vec);
    return 0;
}
```