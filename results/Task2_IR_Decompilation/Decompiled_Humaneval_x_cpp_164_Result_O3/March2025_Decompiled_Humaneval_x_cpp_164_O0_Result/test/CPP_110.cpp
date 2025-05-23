#include <vector>
#include <string>

std::string exchange(std::vector<int> vec1, std::vector<int> vec2) {
    int count = 0;
    for (int i = 0; i < vec1.size(); ++i) {
        if (vec1[i] % 2 == 0) {
            ++count;
        }
    }
    for (int i = 0; i < vec2.size(); ++i) {
        if (vec2[i] % 2 == 0) {
            ++count;
        }
    }
    return count >= vec1.size() ? "YES" : "NO";
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
