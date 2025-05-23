#include <vector>

using namespace std;

bool monotonic(const vector<float>& v) {
    if (v.size() < 2) return true;

    size_t n = v.size();
    size_t i = 0;

    // Check first couple of elements
    if (v[0] >= v[1]) return false;

    // Check next couple of elements
    if (v[1] >= v[2]) return false;

    // Check in blocks of four elements
    for (; i < n - 3; i += 4) {
        if (v[i] >= v[i+1] || v[i+1] >= v[i+2] || v[i+2] >= v[i+3]) {
            return false;
        }
    }

    // Check remaining elements
    switch (n - i) {
        case 3: if (v[i] >= v[i+1] || v[i+1] >= v[i+2]) return false;
        case 2: if (v[i] >= v[i+1]) return false;
        case 1: break;
    }

    return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (monotonic({1, 2, 4, 10}) == true);
    assert (monotonic({1, 2, 4, 20}) == true);
    assert (monotonic({1, 20, 4, 10}) == false);
    assert (monotonic({4, 1, 0, -10}) == true);
    assert (monotonic({4, 1, 1, 0}) == true);
    assert (monotonic({1, 2, 3, 2, 5, 60}) == false);
    assert (monotonic({1, 2, 3, 4, 5, 60}) == true);
    assert (monotonic({9, 9, 9, 9}) == true);
}
