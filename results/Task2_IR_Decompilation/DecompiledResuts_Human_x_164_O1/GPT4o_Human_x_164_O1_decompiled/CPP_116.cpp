```cpp
#include <vector>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

void sort_array(std::vector<int>& vec1, std::vector<int>& vec2) {
    std::vector<int> temp; 
    int* data1 = vec1.data();
    int* data2 = vec2.data();
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();
    
    if (data1 == nullptr || data2 == nullptr) return;

    if (size1 == 0 && size2 == 0) return;

    if (size1 == 0) {
        temp.push_back(data2[0]);
        for (size_t i = 1; i < size2; ++i) {
            int val = data2[i];
            if (val != 0) {
                temp.push_back(val);
            }
        }
    } else if (size2 == 0) {
        temp.push_back(data1[0]);
        for (size_t i = 1; i < size1; ++i) {
            int val = data1[i];
            if (val != 0) {
                temp.push_back(val);
            }
        }
    } else {
        for (size_t i = 0; i < size1; ++i) {
            temp.push_back(data1[i]);
        }
        for (size_t i = 0; i < size2; ++i) {
            temp.push_back(data2[i]);
        }
    }

    for (size_t i = 0; i < temp.size() - 1; ++i) {
        for (size_t j = 0; j < temp.size() - i - 1; ++j) {
            if (temp[j] > temp[j + 1]) {
                std::swap(temp[j], temp[j + 1]);
            }
        }
    }

    vec1.clear();
    vec1.insert(vec1.end(), temp.begin(), temp.end());
}
```