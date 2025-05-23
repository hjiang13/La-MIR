```cpp
#include <vector>
#include <string>
#include <cstdio>
#include <cstdarg>

int skjkasdkd(std::vector<int>& v) {
    int* begin = &v[0];
    int* end = &v[v.size()];

    int diff = end - begin;
    if (diff == 0) {
        return 0;
    }

    int min_diff = diff / 4;
    min_diff = std::max(min_diff, 1);

    int max_val = 0;
    int count = 0;
    for (int* it = begin; it != end; ++it) {
        if (*it > max_val) {
            max_val = *it;
            count++;
        }
    }

    return count;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int result = skjkasdkd(vec);
    printf("%d\n", result);

    return 0;
}
```