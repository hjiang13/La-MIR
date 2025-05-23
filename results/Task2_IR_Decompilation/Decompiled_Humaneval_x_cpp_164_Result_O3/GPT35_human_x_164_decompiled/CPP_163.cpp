```c++
#include <vector>

void generate_integers(std::vector<int>& vec, int start, int end) {
    int size = end < start ? start : end;
    int capacity = end < start ? end : start;
    
    vec._M_impl._M_start = new int[size];
    vec._M_impl._M_finish = vec._M_impl._M_start;
    vec._M_impl._M_end_of_storage = vec._M_impl._M_start + size;
    
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            vec.push_back(i);
        }
    }
}
```