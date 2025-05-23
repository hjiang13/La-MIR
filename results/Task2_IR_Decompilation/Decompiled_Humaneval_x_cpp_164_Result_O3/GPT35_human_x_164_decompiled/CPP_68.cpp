```c++
#include <vector>

void pluck(std::vector<int>& result, const std::vector<int>& input) {
    std::vector<int> *in = const_cast<std::vector<int>*>(&input);
    int *in_begin = &(*in)[0];
    int *in_end = in_begin + in->size();
    
    int *out_begin = &result[0];
    int *out_end = out_begin + result.size();
    
    std::memset(&result[0], 0, result.size() * sizeof(int));
    
    if (in->data() == in_end) {
        return;
    }
    
    for (int i = 0; i < in->size(); ++i) {
        int val = in_begin[i];
        if ((val & 1) == 0) {
            continue;
        }
        
        int *out_ptr = out_begin;
        while (out_ptr != out_end && *out_ptr < val) {
            ++out_ptr;
        }
        
        if (out_ptr == out_end) {
            break;
        }
        
        std::copy_backward(out_ptr, out_end - 1, out_end);
        *out_ptr = val;
    }
}
```