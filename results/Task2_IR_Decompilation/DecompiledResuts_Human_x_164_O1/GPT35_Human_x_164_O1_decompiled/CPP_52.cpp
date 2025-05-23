```c
#include <vector>

bool below_threshold(std::vector<int> &v, int threshold) {
    int *begin = v._M_impl._M_start._M_p;
    int *end = v._M_impl._M_finish._M_p;
    
    int size = end - begin;
    int max_iterations = std::max(size >> 2, 1);
    
    if (*begin < threshold) {
        int i = 1;
        for (; i < max_iterations && *(begin + i) < threshold; ++i);
        
        return i == max_iterations;
    }
    
    return true;
}
```