#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

void exchange(std::string &result, const std::vector<int> &vec1, const std::vector<int> &vec2) {
    int *data1 = const_cast<int*>(vec1.data());
    int *data2 = const_cast<int*>(vec2.data());
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();
    size_t minSize = std::min(size1, size2);
    
    for (size_t i = 0; i < minSize; ++i) {
        data1[i] = !data1[i] + data2[i];
    }

    result.resize(3);
    std::memcpy(&result[0], "YES", 3);
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
