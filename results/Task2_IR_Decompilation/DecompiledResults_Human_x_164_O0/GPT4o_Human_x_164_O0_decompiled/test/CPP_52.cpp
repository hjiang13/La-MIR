#include <vector>

bool below_threshold(const std::vector<int>& vec, int threshold) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] >= threshold) {
            return false;
        }
    }
    return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_threshold({1, 2, 4, 10}, 100));
    assert (not(below_threshold({1, 20, 4, 10}, 5)));
    assert (below_threshold({1, 20, 4, 10}, 21));
    assert (below_threshold({1, 20, 4, 10}, 22));
    assert (below_threshold({1, 8, 4, 10}, 11));
    assert (not(below_threshold({1, 8, 4, 10}, 10)));
}
