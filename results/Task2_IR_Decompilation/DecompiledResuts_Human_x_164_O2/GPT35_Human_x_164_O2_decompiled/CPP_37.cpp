```cpp
#include <vector>
#include <algorithm>

void sort_even(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    if (input.empty()) {
        return;
    }

    auto it = input.begin();
    auto end = input.end();
    float prev = *it;
    ++it;

    while (it != end) {
        float current = *it;
        if (current < prev) {
            result.push_back(current);
        }
        prev = current;
        ++it;
    }
}

void sort_odd(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    if (input.empty()) {
        return;
    }

    auto it = input.begin();
    auto end = input.end();
    float prev = *it;
    ++it;

    while (it != end) {
        float current = *it;
        if (current > prev) {
            result.push_back(current);
        }
        prev = current;
        ++it;
    }
}

int main() {
    std::vector<float> input = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> result_even;
    std::vector<float> result_odd;

    sort_even(result_even, input);
    sort_odd(result_odd, input);

    return 0;
}
```