#include <vector>
#include <algorithm>

bool triples_sum_to_zero(std::vector<int>& vec) {
    int* begin = &vec[0];
    int* end = &vec[0] + vec.size();

    long diff = end - begin;
    long max_diff = std::max(diff, 1L);

    for (long i = 0; i < max_diff; ++i) {
        for (long j = i + 1; j < max_diff; ++j) {
            for (long k = j + 1; k < max_diff; ++k) {
                if (begin[i] + begin[j] + begin[k] == 0) {
                    return true;
                }
            }
        }
    }

    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (triples_sum_to_zero({1, 3, 5, 0}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -1}) == false);
    assert (triples_sum_to_zero({1, 3, -2, 1}) == true);
    assert (triples_sum_to_zero({1, 2, 3, 7}) == false);
    assert (triples_sum_to_zero({1, 2, 5, 7}) == false);
    assert (triples_sum_to_zero({2, 4, -5, 3, 9, 7}) == true);
    assert (triples_sum_to_zero({1}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -100}) == false);
    assert (triples_sum_to_zero({100, 3, 5, -100}) == false);
}
