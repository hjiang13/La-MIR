#include <vector>
#include <iostream>
#include <stdexcept>

void get_positive(std::vector<float>& vec, const std::vector<float>& input) {
    vec.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        float value = input[i];
        if (value > 0.0f) {
            vec.push_back(value);
        }
    }
}

void _M_realloc_insert(std::vector<float>& vec, float* position, float* value) {
    if (vec.size() >= vec.capacity()) {
        throw std::length_error("vector::_M_realloc_insert");
    }
    size_t index = position - vec.data();
    vec.resize(vec.size() + 1);
    for (size_t i = vec.size() - 1; i > index; --i) {
        vec[i] = vec[i - 1];
    }
    vec[index] = *value;
}

int main() {
    std::vector<float> input = { -1.0f, 2.0f, -3.0f, 4.0f };
    std::vector<float> positives;

    try {
        get_positive(positives, input);
        for (float val : positives) {
            std::cout << val << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

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
    assert (issame(get_positive({-1, -2, 4, 5, 6}) , {4, 5, 6} ));
    assert (issame(get_positive({5, 3, -5, 2, 3, 3, 9, 0, 123, 1, -10}) , {5, 3, 2, 3, 3, 9, 123, 1}));
     assert (issame(get_positive({-1, -2}) , {} ));
     assert (issame(get_positive({}) , {}));
}
