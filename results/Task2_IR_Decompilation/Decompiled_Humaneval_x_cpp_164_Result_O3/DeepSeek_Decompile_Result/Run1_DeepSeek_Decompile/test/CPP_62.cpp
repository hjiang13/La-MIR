#include <vector>
#include <stdexcept>

class DerivativeVector {
public:
    DerivativeVector(const std::vector<float>& input_vector) {
        if (input_vector.empty()) {
            // Handle empty input if necessary
            return;
        }

        try {
            resize(input_vector.size());
        } catch (const std::length_error& e) {
            throw std::length_error("vector::_M_realloc_insert");
        }

        for (size_t i = 0; i < input_vector.size(); ++i) {
            (*this)[i] = input_vector[i] * static_cast<float>(i + 1);
        }
    }

    void resize(size_t new_size) {
        if (new_size > capacity()) {
            // Implement reallocation logic here
        }
        // Update size_ member variable
    }

    size_t size() const { /* return current size */ }
    size_t capacity() const { /* return current capacity */ }
};

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
    assert (issame(derivative({3, 1, 2, 4, 5}) , {1, 4, 12, 20}));
    assert (issame(derivative({1, 2, 3}) , {2, 6}));
    assert (issame(derivative({3, 2, 1}) , {2, 2}));
    assert (issame(derivative({3, 2, 1, 0, 4}) , {2, 2, 0, 16}));
    assert (issame(derivative({1}) , {}));
}
