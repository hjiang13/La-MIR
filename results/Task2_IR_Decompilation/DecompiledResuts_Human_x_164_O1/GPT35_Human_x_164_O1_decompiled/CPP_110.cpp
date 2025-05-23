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
```