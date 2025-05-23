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

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(sort_even({1, 2, 3}), {1, 2, 3}));
    assert (issame(sort_even({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10}) , {-10, 3, -5, 2, -3, 3, 5, 0, 9, 1, 123}));
    assert (issame(sort_even({5, 8, -12, 4, 23, 2, 3, 11, 12, -10}) , {-12, 8, 3, 4, 5, 2, 12, 11, 23, -10}));
}
