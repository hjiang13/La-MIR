#include <vector>

bool pairs_sum_to_zero(const std::vector<int>& vec) {
    auto start = vec.data();
    auto end = start + vec.size();
    
    if (end - start == 0) {
        return false;
    }

    int n = (end - start) / 4; // Assuming 4 bytes per int
    if (n == 0) {
        return false;
    }
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int val = start[i];
        if (val == 0) {
            return true;
        }
        count++;
    }

    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (pairs_sum_to_zero({1, 3, 5, 0}) == false);
    assert (pairs_sum_to_zero({1, 3, -2, 1}) == false);
    assert (pairs_sum_to_zero({1, 2, 3, 7}) == false);
    assert (pairs_sum_to_zero({2, 4, -5, 3, 5, 7}) == true);
    assert (pairs_sum_to_zero({1}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 30}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 31}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 30}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 31}) == false);
}
