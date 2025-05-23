#include <vector>
#include <cstdint>

bool triples_sum_to_zero(std::vector<int> &vec) {
    int32_t *data = vec.data();
    int32_t *end = data + vec.size();
    int64_t count = 0;

    while (data < end) {
        int32_t value = *data++;
        count++;
        if (value == 0) {
            return false;
        }
    }

    return count == 0;
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
