```cpp
#include <vector>
#include <string>
#include <stdarg.h>

int skjkasdkd(std::vector<int>& vec) {
    int* begin = &vec[0];
    int* end = &vec[vec.size() - 1];
    int size = end - begin;
    
    if (size == 0) {
        return 0;
    }
    
    int max_size = std::max(size >> 2, 1);
    
    int count = 0;
    int max_count = 0;
    
    for (int i = 0; i < size; i++) {
        if (begin[i] > count) {
            count = begin[i];
        } else {
            if (count < 4) {
                count = std::min(count, begin[i]);
            }
            else {
                if (begin[i] % (count + 1) == 0) {
                    count = 0;
                } else {
                    count = 1;
                }
            }
        }
        
        if (count == 0) {
            max_count = std::max(max_count, i);
        }
    }
    
    return max_count;
}
```