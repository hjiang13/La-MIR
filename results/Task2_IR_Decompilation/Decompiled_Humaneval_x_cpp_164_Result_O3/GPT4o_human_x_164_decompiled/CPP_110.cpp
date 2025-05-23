```cpp
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
```