#include <vector>
#include <cstdint>

bool will_it_fly(std::vector<int> &vec, int n) {
    auto base_data = vec._Myptr(); // Assuming a custom implementation for accessing internal data
    auto base_size = vec.size(); 
    int64_t base_ptr = reinterpret_cast<int64_t>(base_data);
    int64_t vec_ptr = reinterpret_cast<int64_t>(&vec);

    int64_t offset = (base_ptr - vec_ptr) >> 2; // Assuming an integer size of 4 bytes
    if (offset == 0) {
        return true;
    }
    
    int64_t max_offset = std::max(offset, static_cast<int64_t>(1));
    int32_t sum = 0;
    int64_t index = 0;
    
    while (index < max_offset) {
        int32_t current_value = base_data[index];
        int32_t next_value = base_data[index + 1];
        if (current_value != next_value) {
            return false;
        }
        sum += current_value;
        index++;
        if (index == max_offset) {
            break;
        }
    }
    
    return (n >= sum);
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (will_it_fly({3, 2, 3}, 9)==true);
    assert (will_it_fly({1, 2}, 5) == false);
    assert (will_it_fly({3}, 5) == true);
    assert (will_it_fly({3, 2, 3}, 1) == false);
    assert (will_it_fly({1, 2, 3}, 6) ==false);
    assert (will_it_fly({5}, 5) == true);
}
