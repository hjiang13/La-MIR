#include <vector>

int max_fill(std::vector<std::vector<int>>* vec, int val) {
    auto* vec_impl = vec->std::_Vector_base<std::vector<int>, std::allocator<std::vector<int>>::_Vector_impl;
    auto* data = vec_impl->_Vector_impl_data;
    
    int size = (data->end - data->start) / sizeof(int);
    int max_size = std::max(size / 24, 1);
    
    int sum = 0;
    for (int i = 0; i < max_size; i++) {
        auto* sub_vec_data = data->start + i * 24;
        
        for (int j = 0; j < 24; j++) {
            sum += sub_vec_data[j];
        }
    }
    
    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (max_fill({{0,0,1,0}, {0,1,0,0}, {1,1,1,1}}, 1) == 6);
    assert (max_fill({{0,0,1,1}, {0,0,0,0}, {1,1,1,1}, {0,1,1,1}}, 2) == 5);
    assert (max_fill({{0,0,0}, {0,0,0}}, 5) == 0);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 2) == 4);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 9) == 2);
}
