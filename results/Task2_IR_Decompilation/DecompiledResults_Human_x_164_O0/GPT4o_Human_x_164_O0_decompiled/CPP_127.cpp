```cpp
#include <vector>
#include <string>
#include <iostream>

std::string intersection(std::string &result, std::vector<int> &vec1, std::vector<int> &vec2) {
    int maxSize = std::max(vec1.size(), vec2.size());
    int minSize = std::min(vec1.size(), vec2.size());
    int diff = minSize - maxSize;

    if (diff < 2) {
        result = "NO";
        return result;
    }

    int count = 0;
    while (true) {
        int currentCount = count * count;
        if (currentCount <= diff) {
            count++;
        } else {
            result = "YES";
            break;
        }
    }
    
    return result;
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {6, 7, 8, 9};

    std::string result;
    intersection(result, vec1, vec2);
    std::cout << result << std::endl;

    return 0;
}
```