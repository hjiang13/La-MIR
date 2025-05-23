#include <stdint.h>

int32_t triples_sum_to_zero(int32_t* data, int64_t size) {
    int32_t result = 2;
    for (int64_t i = 0; i < size; i++) {
        for (int64_t j = i + 1; j < size; j++) {
            int32_t sum = data[i] + data[j];
            for (int64_t k = j + 1; k < size; k++) {
                if (sum == -data[k]) {
                    result = 1;
                    break;
                }
            }
            if (result == 1) break;
        }
        if (result == 1) break;
    }
    return result != 2;
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
