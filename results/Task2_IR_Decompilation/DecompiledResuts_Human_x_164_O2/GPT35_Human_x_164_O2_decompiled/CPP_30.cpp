```cpp
#include <vector>

void get_positive(std::vector<float>& result, std::vector<float>& input) {
    result.clear();
    float* begin = &input[0];
    float* end = begin + input.size();

    for (float* it = begin; it != end; ++it) {
        if (*it > 0.0) {
            result.push_back(*it);
        }
    }
}

int main() {
    std::vector<float> input = {1.0, -2.0, 3.0, -4.0, 5.0};
    std::vector<float> result;
    
    get_positive(result, input);
    
    return 0;
}
```