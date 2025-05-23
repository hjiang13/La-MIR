#include <vector>
using namespace std;

bool monotonic(const vector<float>& v) {
    size_t n = v.size();
    if (n < 2) return true;

    bool increasing = v[1] > v[0];
    bool decreasing = v[1] < v[0];

    if (!increasing && !decreasing) return false;

    for (size_t i = 2; i < n; ++i) {
        if (increasing && v[i] < v[i-1]) return false;
        if (decreasing && v[i] > v[i-1]) return false;
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
