#include <vector>

using namespace std;

bool triples_sum_to_zero(const vector<int>& arr) {
    if (arr.size() < 3) {
        return false;
    }
    
    size_t n = arr.size();
    size_t max = n / 3;

    for (size_t i = 0; i < max; ++i) {
        for (size_t j = i + 1; j < max; ++j) {
            for (size_t k = j + 1; k < max; ++k) {
                if (arr[i] + arr[j] + arr[k] == 0) {
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
