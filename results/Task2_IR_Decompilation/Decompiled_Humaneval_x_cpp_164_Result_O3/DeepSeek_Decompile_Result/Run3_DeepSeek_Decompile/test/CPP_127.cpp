#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string intersection(const vector<int>& vec1, const vector<int>& vec2) {
    if (vec1.empty() || vec2.empty()) {
        return "NO";
    }

    int a = vec1[0];
    int b = vec2[0];
    int c = vec1[1];
    int d = vec2[1];

    int x = min(a, b);
    int y = min(c, d);

    int diff = y - x;

    if (diff < 2) {
        return "NO";
    }

    if (diff < 4) {
        return "YES";
    }

    for (int i = 2; i * i <= diff; ++i) {
        if (diff % i == 0) {
            return "YES";
        }
    }

    return "NO";
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
