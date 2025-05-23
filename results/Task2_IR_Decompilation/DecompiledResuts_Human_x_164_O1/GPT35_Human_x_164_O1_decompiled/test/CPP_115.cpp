```c++
#include <vector>

int max_fill(std::vector<std::vector<int>>* vec, int val) {
    auto* vec_data = (*vec)[0].data();
    auto* vec_end = (*vec)[0].data() + (*vec)[0].size();
    
    if (vec_data == vec_end) {
        return 0;
    }
    
    int total = 0;
    int count = 0;
    
    for (int i = 0; i < vec->size(); ++i) {
        auto* inner_vec_data = (*vec)[i].data();
        auto* inner_vec_end = (*vec)[i].data() + (*vec)[i].size();
        
        if (inner_vec_data == inner_vec_end) {
            continue;
        }
        
        for (int j = 0; j < (*vec)[i].size(); ++j) {
            total += inner_vec_data[j];
            ++count;
            
            if (count == val) {
                return total;
            }
        }
    }
    
    return total;
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
