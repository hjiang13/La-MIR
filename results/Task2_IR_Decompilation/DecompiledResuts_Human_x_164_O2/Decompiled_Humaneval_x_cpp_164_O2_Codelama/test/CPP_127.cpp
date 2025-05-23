#include <iostream>
#include <vector>
#include <string>

using namespace std;

string intersection(vector<int> v1, vector<int> v2) {
    int len1 = v1.size();
    int len2 = v2.size();
    int i = 0;
    int j = 0;
    string result = "";

    while (i < len1 && j < len2) {
        if (v1[i] == v2[j]) {
            result += to_string(v1[i]);
            i++;
            j++;
        } else if (v1[i] < v2[j]) {
            i++;
        } else {
            j++;
        }
    }

    if (result.empty()) {
        result = "YES";
    }

    return result;
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
