#include <vector>

using namespace std;

bool will_it_fly(vector<int> vec, int n) {
    if (vec.empty()) {
        return false;
    }

    int size = (int)((ptrdiff_t)(vec.end() - vec.begin()) >> 2);
    if (size == 0) {
        return false;
    }

    size = max(size, 1);

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (vec[i] != vec[(i ^ (size - 1)) + (size - 1)]) {
            sum += vec[i];
        }
    }

    return sum <= n;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (will_it_fly({3, 2, 3}, 9)==true);
    assert (will_it_fly({1, 2}, 5) == false);
    assert (will_it_fly({3}, 5) == true);
    assert (will_it_fly({3, 2, 3}, 1) == false);
    assert (will_it_fly({1, 2, 3}, 6) ==false);
    assert (will_it_fly({5}, 5) == true);
}
