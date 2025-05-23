```cpp
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
```