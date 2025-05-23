#include <vector>

bool move_one_ball(std::vector<int>& vec) {
    if (vec.size() == 0) {
        return true;
    }

    int count = 0;
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            ++count;
        }
    }

    if (vec.back() > vec.front()) {
        ++count;
    }

    return count < 2;
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
