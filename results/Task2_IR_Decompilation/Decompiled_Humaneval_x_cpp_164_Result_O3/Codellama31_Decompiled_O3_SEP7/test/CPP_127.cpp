#include <string>
#include <vector>

using namespace std;

string intersection(vector<int> v1, vector<int> v2) {
    int size1 = v1.size();
    int size2 = v2.size();
    if (size1 == 0 || size2 == 0) {
        return "";
    }
    int minSize = min(size1, size2);
    int maxSize = max(size1, size2);
    int i = 0;
    int j = 0;
    while (i < minSize && j < maxSize) {
        if (v1[i] == v2[j]) {
            return "YES";
        }
        i++;
        j++;
    }
    return "";
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
