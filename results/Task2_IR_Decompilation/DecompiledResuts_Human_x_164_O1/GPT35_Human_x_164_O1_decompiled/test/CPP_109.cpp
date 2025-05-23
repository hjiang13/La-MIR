```cpp
#include <vector>

bool move_one_ball(std::vector<int> &vec) {
    int *endPtr = vec[0]._M_impl._M_finish;
    int *beginPtr = vec[0]._M_impl._M_start;
    long diff = (long)endPtr - (long)beginPtr;
    long numElements = diff >> 2;
    if (diff == 0) {
        return true;
    } else {
        if (numElements > 1) {
            int sum = 0;
            for (int i = 0; i < numElements - 1; i++) {
                int current = *(beginPtr + i);
                int next = *(beginPtr + i + 1);
                if (current > next) {
                    sum++;
                }
            }
            return sum < 2;
        } else {
            int i = 1;
            int sum = 0;
            while (i < numElements) {
                int current = *(beginPtr + i);
                int prev = *(beginPtr + i - 1);
                if (current < prev) {
                    sum++;
                }
                i++;
            }
            return sum < 2;
        }
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (move_one_ball({3, 4, 5, 1, 2})==true);
    assert (move_one_ball({3, 5, 10, 1, 2})==true);
    assert (move_one_ball({4, 3, 1, 2})==false);
    assert (move_one_ball({3, 5, 4, 1, 2})==false);
    assert (move_one_ball({})==true);
}
