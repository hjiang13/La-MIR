#include <vector>

using namespace std;

bool below_threshold(const vector<int>* v, int threshold) {
    if (v->empty()) {
        return true;
    }

    vector<int>::size_type size = v->size();
    size_t max_block = size / 4;  // Divide size by 4 for block comparison

    for (size_t i = 0; i < max_block; ++i) {
        // Check each element in the current block
        if ((*v)[i * 4] >= threshold ||
            (*v)[i * 4 + 1] >= threshold ||
            (*v)[i * 4 + 2] >= threshold ||
            (*v)[i * 4 + 3] >= threshold) {
            return false;
        }
    }

    // Check remaining elements if size is not a multiple of 4
    size_t remaining = size % 4;
    for (size_t i = 0; i < remaining; ++i) {
        if ((*v)[max_block * 4 + i] >= threshold) {
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
