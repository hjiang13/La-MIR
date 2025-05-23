```cpp
#include <vector>

void common(std::vector<int>& result, const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int>* vec1_base = &vec1;
    std::vector<int>* vec1_begin = &vec1;
    std::vector<int>* vec2_base = &vec2;
    std::vector<int>* vec2_begin = &vec2;
    
    size_t vec1_size = vec1_base->size();
    size_t vec2_size = vec2_base->size();
    
    if (vec1_size == 0 || vec2_size == 0) {
        return;
    }
    
    size_t vec1_index = 1;
    size_t vec2_index = 1;
    
    while (vec1_index < vec1_size && vec2_index < vec2_size) {
        int vec1_value = (*vec1_base)[vec1_index];
        int vec2_value = (*vec2_base)[vec2_index];
        
        if (vec1_value < vec2_value) {
            result.push_back(vec1_value);
            vec1_index++;
        } else {
            result.push_back(vec2_value);
            vec2_index++;
        }
    }
    
    while (vec1_index < vec1_size) {
        result.push_back((*vec1_base)[vec1_index]);
        vec1_index++;
    }
    
    while (vec2_index < vec2_size) {
        result.push_back((*vec2_base)[vec2_index]);
        vec2_index++;
    }
}
```