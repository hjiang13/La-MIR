#include <vector>
#include <string>

using namespace std;

string intersection(const vector<int>& a, const vector<int>& b) {
    size_t size_a = a.size();
    size_t size_b = b.size();
    int diff = abs(static_cast<int>(size_a) - static_cast<int>(size_b));

    if (diff < 2) {
        return "YES";
    }

    if (diff < 4) {
        for (int i = 2; i <= diff; ++i) {
            if (diff % i == 0) {
                return "YES";
            }
        }
    }

    return "YES";
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (intersection({1, 2}, {2, 3}) == "NO");
    assert (intersection({-1, 1}, {0, 4}) == "NO");
    assert (intersection({-3, -1}, {-5, 5}) == "YES");
    assert (intersection({-2, 2}, {-4, 0}) == "YES");
    assert (intersection({-11, 2}, {-1, -1}) == "NO");
    assert (intersection({1, 2}, {3, 5}) == "NO");
    assert (intersection({1, 2}, {1, 2}) == "NO");
    assert (intersection({-2, -2}, {-3, -2}) == "NO");
}
