```c++
#include <vector>

bool triples_sum_to_zero(std::vector<int>& vec) {
    int* data_begin = vec[0]._M_impl._M_start._M_p;
    int* data_end = vec[0]._M_impl._M_finish._M_p;
    
    int64_t diff = (int64_t)data_begin - (int64_t)data_end;
    int64_t size = diff >> 2;
    
    if (diff == 0) {
        return false;
    }
    
    int64_t max_size = std::max(size, (int64_t)1);
    
    int count = 2;
    int64_t index = 1;
    
    bool flag = true;
    
    while (size > index) {
        if (size == max_size) {
            return false;
        }
        
        int64_t current_index = index;
        index++;
        
        int* current_data = data_end + current_index;
        int* next_data = data_end + index;
        
        int current_val = *current_data;
        int next_val = *next_data;
        
        int sum = current_val + next_val;
        
        if (sum == 0) {
            return true;
        }
    }
    
    return false;
}
```