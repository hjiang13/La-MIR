#include <vector>

bool move_one_ball(std::vector<int> &vec) {
    int *data = vec.data();
    int *end = data + vec.size();
    int size = end - data;
    
    if (size == 0) return true;
    
    int count = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (data[i] > data[i + 1]) {
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
