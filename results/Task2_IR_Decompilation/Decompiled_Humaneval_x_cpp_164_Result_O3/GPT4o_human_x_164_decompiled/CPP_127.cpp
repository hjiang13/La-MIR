```cpp
#include <vector>
#include <string>
#include <cstring>

void intersection(std::string& result, const std::vector<int>& vec1, const std::vector<int>& vec2) {
    int minSize = std::min(vec1.size(), vec2.size());
    int threshold = 2;

    if (minSize < 4) {
        result = "YES";
        return;
    }

    for (int i = 2; i < minSize; i++) {
        int count = 0;

        for (int j = 0; j < minSize; j++) {
            if (vec1[j] % i == 0) {
                count++;
            }
        }

        if (count > threshold) {
            result = "YES";
            return;
        }
    }

    result = "NO";
}
```