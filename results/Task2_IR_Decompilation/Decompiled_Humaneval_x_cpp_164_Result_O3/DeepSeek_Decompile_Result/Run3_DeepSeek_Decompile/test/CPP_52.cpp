#include <vector>

using namespace std;

bool below_threshold(const vector<int>& v, int threshold) {
    if (v.empty()) {
        return true;
    }
    size_t size = v.size();
    size_t cap = size >> 2; // Equivalent to size / 4
    size_t max_cap = (cap == 0) ? 1 : cap;
    if (size < threshold) {
        return false;
    }
    for (size_t i = 1; i <= max_cap; ++i) {
        if (v[i] >= threshold) {
            return true;
        }
    }
    return false;
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
