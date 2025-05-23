#include <vector>

using namespace std;

int smallest_change(const vector<int>& v) {
    int n = v.size();
    int count = 0;
    for (int i = 0; i < (n - 1) / 4; ++i) {
        if (v[i] != v[i + 1]) {
            ++count;
        }
    }
    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (smallest_change({1,2,3,5,4,7,9,6}) == 4);
    assert (smallest_change({1, 2, 3, 4, 3, 2, 2}) == 1);
    assert (smallest_change({1, 4, 2}) == 1);
    assert (smallest_change({1, 4, 4, 2}) == 1);
    assert (smallest_change({1, 2, 3, 2, 1}) == 0);
    assert (smallest_change({3, 1, 1, 3}) == 0);
    assert (smallest_change({1}) == 0);
    assert (smallest_change({0, 1}) == 1);
}
