```cpp
#include <vector>

void intersperse(std::vector<int>& result, std::vector<int>& input, int value) {
    result.clear();
    int* input_begin = &input[0];
    int* input_end = input_begin + input.size();
    
    if (input_begin == input_end) {
        return;
    }
    
    result.resize(2 * input.size() - 1);
    int* result_begin = &result[0];
    int* result_end = result_begin + result.size();
    
    while (input_begin != input_end) {
        *result_begin++ = *input_begin++;
        if (input_begin != input_end) {
            *result_begin++ = value;
        }
    }
}
```