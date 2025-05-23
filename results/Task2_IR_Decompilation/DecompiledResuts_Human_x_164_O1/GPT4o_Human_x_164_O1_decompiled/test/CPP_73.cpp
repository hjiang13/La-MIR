#include <vector>

int smallest_change(std::vector<int> const& vec) {
    int* data = vec.data();
    int* end = data + vec.size();
    int count = 0;

    if (data == end) {
        return count;
    }

    for (int* it = data; it < end - 1; ++it) {
        if (*it != *(it + 1)) {
            count++;
        }
    }

    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (smallest_change({1,2,3,5,4,7,9,6}) == 4);
    assert (smallest_change({1, 2, 3, 4, 3, 2, 2}) == 1);
    assert (smallest_change({1, 4, 2}) == 1);
    assert (smallest_change({1, 4, 4, 2}) == 1);
    assert (smallest_change({1, 2, 3, 2, 1}) == 0);
    assert (smallest_change({3, 1, 1, 3}) == 0);
    assert (smallest_change({1}) == 0);
    assert (smallest_change({0, 1}) == 1);
}
