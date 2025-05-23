#include <vector>
#include <string>
#include <cstring>

void intersection(std::string &result, const std::vector<int> &vec1, const std::vector<int> &vec2) {
    int size1 = vec1.size();
    int size2 = vec2.size();
    int minSize = (size1 < size2) ? size1 : size2;

    if (minSize < 2) {
        result = std::string(2, '\0');
        *((uint16_t*)(result.data() + 2)) = 20302;
        *((uint64_t*)(result.data() + 1)) = 2;
        return;
    }

    for (int i = 2; i < minSize; i++) {
        int diff = (vec1[i] < vec2[i]) ? vec2[i] : vec1[i];
        if (diff < 4) {
            result = std::string(3, '\0');
            std::memcpy(result.data() + 3, "YES", 3);
            *((uint64_t*)(result.data() + 1)) = 3;
            return;
        }
    }

    result = std::string(3, '\0');
    std::memcpy(result.data(), "YES", 3);
    *((uint64_t*)(result.data() + 1)) = 3;
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
