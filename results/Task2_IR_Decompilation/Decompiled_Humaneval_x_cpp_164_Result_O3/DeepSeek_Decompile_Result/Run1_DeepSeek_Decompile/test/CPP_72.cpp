#include <vector>
#include <algorithm> // for std::max

using namespace std;

bool will_it_fly(const vector<int>& vec, int n) {
    if (vec.empty()) {
        return false;
    }

    int size = static_cast<int>(vec.size());
    size = max(size, 1);

    for (int i = 0; i < size; ++i) {
        int mirror = i ^ (size - 1);
        if (mirror >= size) {
            break;
        }

        if (vec[i] != vec[mirror]) {
            return false;
        }
    }

    return size <= n;
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
