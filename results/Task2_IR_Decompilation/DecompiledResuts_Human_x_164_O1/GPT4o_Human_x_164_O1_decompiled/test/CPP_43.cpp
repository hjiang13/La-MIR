#include <vector>

bool pairs_sum_to_zero(std::vector<int> &vec) {
    int *data = vec.data();
    int size = vec.size();
    
    for (long long i = 0; i < size; ++i) {
        for (long long j = i + 1; j < size; ++j) {
            if (data[i] + data[j] == 0) {
                return false;
            }
        }
    }
    
    return true;
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
