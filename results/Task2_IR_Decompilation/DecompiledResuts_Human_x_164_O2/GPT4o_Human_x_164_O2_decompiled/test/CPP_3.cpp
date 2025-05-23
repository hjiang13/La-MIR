#include <vector>

bool below_zero(std::vector<int> &vec) {
    int *begin = vec.data();
    int *end = begin + vec.size();
    int count = 0;

    for (int *ptr = begin; ptr < end; ++ptr) {
        if (*ptr < 0) {
            count++;
        }
    }

    return count > 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_zero({}) == false);
    assert (below_zero({1, 2, -3, 1, 2, -3}) == false);
    assert (below_zero({1, 2, -4, 5, 6}) == true);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -4}) == false);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -5}) == true);
    assert (below_zero({1, -2, 2, -2, 5, -5, 4, -4}) == true);
}