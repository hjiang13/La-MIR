#include <vector>
#include <algorithm>

using namespace std;

bool move_one_ball(vector<int>& balls) {
    if (balls.empty()) {
        return true;
    }

    int* start = &balls[0];
    int* end = start + balls.size();

    // Vectorized processing of 4 elements at a time
    size_t size = end - start;
    size_t num_blocks = (size >> 2) - 1;

    int sum = 0;
    for (size_t i = 0; i <= num_blocks; ++i) {
        int* ptr = start + i * 4;
        int a = *ptr;
        int b = *(ptr + 1);
        int c = *(ptr + 2);
        int d = *(ptr + 3);

        if (a < b && b < c && c < d) {
            sum += 4;
        }
    }

    if (sum < 2) {
        return true;
    }

    // Check remaining elements
    for (size_t i = 0; i < balls.size() - 1; ++i) {
        if (balls[i] < balls[i+1]) {
            return false;
        }
    }

    return true;
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
