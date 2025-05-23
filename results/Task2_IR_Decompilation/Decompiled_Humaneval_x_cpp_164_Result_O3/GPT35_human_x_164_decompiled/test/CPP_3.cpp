#include <vector>
#include <algorithm>

bool below_zero(std::vector<int> &vec) {
    auto *begin = vec.data();
    auto *end = begin + vec.size();
    auto diff = std::distance(begin, end);
    
    if (diff == 0) {
        return false;
    }
    
    auto max_diff = std::max(diff, static_cast<decltype(diff)>(1));
    
    int sum = 0;
    for (auto i = begin; i != end; ++i) {
        sum += *i;
        if (sum < 0) {
            return true;
        }
    }
    
    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_zero({}) == false);
    assert (below_zero({1, 2, -3, 1, 2, -3}) == false);
    assert (below_zero({1, 2, -4, 5, 6}) == true);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -4}) == false);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -5}) == true);
    assert (below_zero({1, -2, 2, -2, 5, -5, 4, -4}) == true);
}