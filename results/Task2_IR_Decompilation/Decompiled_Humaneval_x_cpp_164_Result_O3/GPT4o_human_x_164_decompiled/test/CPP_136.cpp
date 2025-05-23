#include <vector>
#include <cstring>
#include <cstdint>
#include <cstdlib>

void largest_smallest_integers(std::vector<int>* result, const std::vector<int>* input) {
    int* input_data = input->_Vector_base::_Vector_impl._Vector_impl_data;
    int* result_data = static_cast<int*>(std::malloc(2 * sizeof(int)));
    
    if (input_data == nullptr) {
        std::memset(result_data, 0, 2 * sizeof(int));
        result->_Vector_base::_Vector_impl._Vector_impl_data = result_data;
        return;
    }
    
    int largest = 0;
    int smallest = 0;
    size_t size = (reinterpret_cast<uintptr_t>(input_data[1]) - reinterpret_cast<uintptr_t>(input_data[0])) / sizeof(int);
    
    for (size_t i = 0; i < size; ++i) {
        int value = input_data[i];
        if (i == 0 || value > largest) {
            largest = value;
        }
        if (i == 0 || value < smallest) {
            smallest = value;
        }
    }
    
    result_data[0] = smallest;
    result_data[1] = largest;
    result->_Vector_base::_Vector_impl._Vector_impl_data = result_data;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(largest_smallest_integers({2, 4, 1, 3, 5, 7}) , {0, 1}));
    assert (issame(largest_smallest_integers({2, 4, 1, 3, 5, 7, 0}) , {0, 1}));
    assert (issame(largest_smallest_integers({1, 3, 2, 4, 5, 6, -2}) , {-2, 1}));
    assert (issame(largest_smallest_integers({4, 5, 3, 6, 2, 7, -7}) , {-7, 2}));
    assert (issame(largest_smallest_integers({7, 3, 8, 4, 9, 2, 5, -9}) , {-9, 2}));
    assert (issame(largest_smallest_integers({}) , {0, 0}));
    assert (issame(largest_smallest_integers({0}) , {0, 0}));
    assert (issame(largest_smallest_integers({-1, -3, -5, -6}) , {-1, 0}));
    assert (issame(largest_smallest_integers({-1, -3, -5, -6, 0}) , {-1, 0}));
    assert (issame(largest_smallest_integers({-6, -4, -4, -3, 1}) , {-3, 1}));
    assert (issame(largest_smallest_integers({-6, -4, -4, -3, -100, 1}) , {-3, 1}));

}
