#include <vector>
#include <cstdint>

bool will_it_fly(std::vector<int>& vec, int limit) {
    int* data = vec.data();
    int* end = data + vec.size();
    int64_t size = reinterpret_cast<int64_t>(end) - reinterpret_cast<int64_t>(data);
    size >>= 2;

    if (size == 0) {
        return true;
    }

    int64_t count = 0;
    int32_t sum = 0;

    while (count < size) {
        int32_t current = data[count];
        count++;
        sum += current;
        
        if (count >= limit) {
            break;
        }
    }

    return (sum <= limit);
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
