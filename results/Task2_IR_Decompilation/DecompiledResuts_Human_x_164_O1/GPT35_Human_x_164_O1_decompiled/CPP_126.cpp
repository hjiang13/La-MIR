```c
#include <vector>

bool is_sorted(std::vector<int> &v) {
    int* data = v._M_impl._M_start;
    int* end = v._M_impl._M_finish;
    
    int size = end - data;
    if (size > 1) {
        for (int i = 1; i < size; ++i) {
            if (data[i] < data[i - 1]) {
                return false;
            }
        }
    }
    
    return true;
}
```