#include <vector>
#include <algorithm>

extern "C" int count_nums(std::vector<int> const& vec) {
    int count = 0;
    size_t size = vec.size();
    
    if (size == 0) {
        return count;
    }
    
    for (size_t i = 0; i < size; ++i) {
        int value = vec[i];
        if (value > 0) {
            count++;
        } else if (value < -9) {
            count += (value % 10 + 0);
            count++;
        }
    }
    
    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_nums({}) == 0);
    assert (count_nums({-1, -2, 0}) == 0);
    assert (count_nums({1, 1, 2, -2, 3, 4, 5}) == 6);
    assert (count_nums({1, 6, 9, -6, 0, 1, 5}) == 5);
    assert (count_nums({1, 100, 98, -7, 1, -1}) == 4);
    assert (count_nums({12, 23, 34, -45, -56, 0}) == 5);
    assert (count_nums({-0, 1}) == 1);
    assert (count_nums({1}) == 1);
}
