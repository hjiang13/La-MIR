```cpp
#include <vector>
#include <string>
#include <cstdio>
#include <cstdarg>

int skjkasdkd(std::vector<int>& v) {
    int* begin = &v[0];
    int* end = &v[v.size()];

    int diff = end - begin;
    if (diff == 0) {
        return 0;
    }

    int min_diff = diff / 4;
    min_diff = std::max(min_diff, 1);

    int max_val = 0;
    int count = 0;
    for (int* it = begin; it != end; ++it) {
        if (*it > max_val) {
            max_val = *it;
            count++;
        }
    }

    return count;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int result = skjkasdkd(vec);
    printf("%d\n", result);

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (skjkasdkd({0,3,2,1,3,5,7,4,5,5,5,2,181,32,4,32,3,2,32,324,4,3}) == 10);
    assert (skjkasdkd({1,0,1,8,2,4597,2,1,3,40,1,2,1,2,4,2,5,1}) == 25);
    assert (skjkasdkd({1,3,1,32,5107,34,83278,109,163,23,2323,32,30,1,9,3}) == 13);
    assert (skjkasdkd({0,724,32,71,99,32,6,0,5,91,83,0,5,6}) == 11);
    assert (skjkasdkd({0,81,12,3,1,21}) == 3);
    assert (skjkasdkd({0,8,1,2,1,7}) == 7);
    assert (skjkasdkd({8191}) == 19);
    assert (skjkasdkd({8191, 123456, 127, 7}) == 19);
    assert (skjkasdkd({127, 97, 8192}) == 10);
}
