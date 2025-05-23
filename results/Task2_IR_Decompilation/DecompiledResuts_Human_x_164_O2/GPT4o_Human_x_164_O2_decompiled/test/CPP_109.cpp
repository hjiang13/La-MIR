#include <vector>

bool move_one_ball(std::vector<int> &v) {
    int *data = v.data();
    int size = v.size();
    
    if (size == 0) {
        return false;
    }
    
    int count = 0;
    
    for (int i = 0; i < size; ++i) {
        if (data[i] > 0) {
            count++;
        }
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
