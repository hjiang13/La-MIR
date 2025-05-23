#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

void exchange(std::string &str, const std::vector<int> &vec1, const std::vector<int> &vec2) {
    int size1 = vec1.size();
    int size2 = vec2.size();
    int count1 = 0;
    int count2 = 0;

    if (size1 == 0 || size2 == 0) {
        return;
    }

    for (int i = 0; i < size1; ++i) {
        count1 += (vec1[i] & 1) ^ 1;
    }

    for (int i = 0; i < size2; ++i) {
        count2 += (vec2[i] & 1) ^ 1;
    }

    if (count1 > count2) {
        str = "YES";
    } else {
        str = "NO";
    }

    str += '\0';
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (exchange({1, 2, 3, 4}, {1, 2, 3, 4}) == "YES");
    assert (exchange({1, 2, 3, 4}, {1, 5, 3, 4}) == "NO");
    assert (exchange({1, 2, 3, 4}, {2, 1, 4, 3}) == "YES" );
    assert (exchange({5, 7, 3}, {2, 6, 4}) == "YES");
    assert (exchange({5, 7, 3}, {2, 6, 3}) == "NO" );
    assert (exchange({3, 2, 6, 1, 8, 9}, {3, 5, 5, 1, 1, 1}) == "NO");
    assert (exchange({100, 200}, {200, 200}) == "YES");
}
