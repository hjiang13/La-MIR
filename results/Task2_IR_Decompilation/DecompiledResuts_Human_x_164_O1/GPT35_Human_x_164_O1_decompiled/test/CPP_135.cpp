```cpp
#include <vector>
#include <algorithm>

int can_arrange(std::vector<int> vec) {
    int* begin = &vec[0];
    int* end = &vec[vec.size() - 1];

    if (begin == end) {
        return -1;
    }

    int size = std::max((end - begin) / 4, 1);

    for (int i = 0; i < size; i++) {
        if (begin[i] > end[i]) {
            return -1;
        }
    }

    return size;
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
