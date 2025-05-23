#include <vector>

int smallest_change(std::vector<int> &vec) {
    int count = 0;
    int index = 0;
    while (true) {
        if (index >= vec.size() - 1) {
            break;
        }
        int value1 = vec[index];
        int value2 = vec[index + 1];
        if (value1 != value2) {
            count++;
        }
        index++;
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
