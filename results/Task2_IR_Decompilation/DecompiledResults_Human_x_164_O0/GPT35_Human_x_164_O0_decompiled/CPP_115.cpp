```cpp
#include <vector>

int max_fill(std::vector<int>* vec, int val) {
    int size = vec->size();
    int sum = 0;

    for (int i = 0; i < size; i++) {
        std::vector<int> temp = (*vec)[i];
        int inner_size = temp.size();

        for (int j = 0; j < inner_size; j++) {
            sum += temp[j];
        }
    }

    return sum;
}
```