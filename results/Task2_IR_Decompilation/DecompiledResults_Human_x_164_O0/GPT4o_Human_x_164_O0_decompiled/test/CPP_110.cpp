#include <vector>
#include <string>

void exchange(std::string &result, const std::vector<int> &vec1, const std::vector<int> &vec2) {
    int count1 = 0;
    int count2 = 0;

    while (count1 < vec1.size()) {
        int value1 = vec1[count1];
        if (value1 % 2 == 0) {
            count1++;
            continue;
        }
        count1++;
    }

    while (count2 < vec2.size()) {
        int value2 = vec2[count2];
        if (value2 % 2 == 0) {
            count2++;
            continue;
        }
        count2++;
    }

    if (count1 >= vec1.size()) {
        result = "NO";
    } else {
        result = "YES";
    }
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
