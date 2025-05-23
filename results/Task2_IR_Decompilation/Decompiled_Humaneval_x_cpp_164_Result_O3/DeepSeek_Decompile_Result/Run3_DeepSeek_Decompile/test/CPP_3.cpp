#include <vector>

using namespace std;

bool below_zero(const vector<int>& v) {
    if (v.empty()) {
        return false;
    }

    size_t n = v.size() / 2;
    int sum = v[0];
    
    if (sum < 0) {
        return true;
    }

    for (size_t i = 1; i < n; ++i) {
        sum += v[i];
        if (sum < 0) {
            return true;
        }
    }

    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_zero({}) == false);
    assert (below_zero({1, 2, -3, 1, 2, -3}) == false);
    assert (below_zero({1, 2, -4, 5, 6}) == true);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -4}) == false);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -5}) == true);
    assert (below_zero({1, -2, 2, -2, 5, -5, 4, -4}) == true);
}