#include <vector>
#include <cstdint>

extern "C" bool triples_sum_to_zero(std::vector<int> *vec) {
    int32_t *data = vec->data();
    int32_t *end = data + vec->size();
    int64_t size = end - data;
    if (size == 0) return false;

    int64_t count = 0;
    int32_t sum = 0;
    for (int64_t i = 0; i < size; ++i) {
        sum += data[i];
        count++;
        if (sum == -count) {
            return true;
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
