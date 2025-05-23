```cpp
#include <vector>

void count_up_to(std::vector<int>& vec, int num) {
    std::memset(&vec, 0, sizeof(vec));
    
    int* begin = &vec[0];
    int* end = &vec[0];
    int* capacity = &vec[2];
    
    *begin = 2;
    
    if (num > 2) {
        int count = 2;
        
        while (count < num) {
            int value = *end;
            int squared = value * value;
            
            if (squared > count) {
                break;
            }
            
            bool insert = true;
            int* temp = begin;
            int* temp_end = end;
            
            while (temp_end != temp) {
                if (*temp_end == value) {
                    insert = false;
                    break;
                }
                temp_end++;
            }
            
            if (insert) {
                *end = value;
                end++;
                count++;
            }
        }
    }
}
```