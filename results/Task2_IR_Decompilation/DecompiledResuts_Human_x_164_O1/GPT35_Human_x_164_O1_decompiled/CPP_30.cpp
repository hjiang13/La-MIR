```cpp
#include <vector>

void get_positive(std::vector<float>& result, std::vector<float>& input) {
    result.clear();
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] > 0.0f) {
            result.push_back(input[i]);
        }
    }
}

int main() {
    std::vector<float> input = {1.0f, -2.0f, 3.0f, -4.0f, 5.0f};
    std::vector<float> result;
    
    get_positive(result, input);
    
    return 0;
}
```