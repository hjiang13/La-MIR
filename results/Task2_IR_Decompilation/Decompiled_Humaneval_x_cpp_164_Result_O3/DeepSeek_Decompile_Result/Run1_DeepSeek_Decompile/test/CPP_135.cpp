#include <vector>
using namespace std;

int can_arrange(vector<int>& vec) {
    if (vec.empty()) {
        return -1;
    }

    int* data = vec.data();
    int size = vec.size();

    if (size == 0) {
        return -1;
    }

    int max_pos = (size >> 2) - 1;
    int remainder = size & 3;

    if (max_pos < 3 && remainder != 0) {
        return -1;
    }

    bool found = false;
    for (int i = 0; i <= max_pos; ++i) {
        if (data[i] != i) {
            found = true;
            break;
        }
    }

    if (!found) {
        return 0;
    }

    for (int i = 0; i < 4; ++i) {
        if (vec[i] != i) {
            return 1;
        }
    }

    return -1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (can_arrange({1,2,4,3,5})==3);
    assert (can_arrange({1,2,4,5})==-1);
    assert (can_arrange({1,4,2,5,6,7,8,9,10})==2);
    assert (can_arrange({4,8,5,7,3})==4);
    assert (can_arrange({})==-1);
}
