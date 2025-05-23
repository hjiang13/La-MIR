```c++
#include <string>
#include <vector>

void exchange(std::string &result, std::vector<int> &vec1, std::vector<int> &vec2) {
    int size1 = vec1.size();
    int size2 = vec2.size();

    for (int i = 0; i < size1; ++i) {
        int val = vec1[i];
        val = val ^ 1;
        result.push_back(static_cast<char>(val));
    }

    for (int i = 0; i < size2; ++i) {
        int val = vec2[i];
        val = val ^ 1;
        result.push_back(static_cast<char>(val));
    }
}

int main() {
    std::string result;
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {6, 7, 8, 9, 10};

    exchange(result, vec1, vec2);

    return 0;
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
