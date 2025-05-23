```cpp
#include <vector>

int solutions(std::vector<int> &vec) {
    int result = 0;
    int index = 0;

    while (true) {
        if (index * 2 < vec.size()) {
            int value = vec[index * 2];
            if (value % 2 == 1) {
                result += value;
            }
        } else {
            break;
        }
        
        index += 1;
    }

    return result;
}

int main() {
    std::vector<int> vec = { /* Initialize with values */ };
    int result = solutions(vec);
    return result;
}
```