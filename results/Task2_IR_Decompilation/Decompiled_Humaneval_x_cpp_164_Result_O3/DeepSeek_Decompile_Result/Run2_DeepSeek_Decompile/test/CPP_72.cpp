#include <vector>

using namespace std;

bool will_it_fly(vector<int>& vec, int n) {
    if (vec.empty()) {
        return false;
    }

    size_t size = (vec.end() - vec.begin()) >> 1;
    size_t max_size = size;

    size_t index = 0;
    int sum = 0;

    while (index < max_size) {
        int a = vec[index];
        int b = vec[size - index - 1];

        if (a != b) {
            return false;
        }

        sum += a;
        index++;
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
