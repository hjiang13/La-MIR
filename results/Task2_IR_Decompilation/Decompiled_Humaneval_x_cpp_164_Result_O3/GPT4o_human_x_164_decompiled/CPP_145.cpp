```cpp
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cstring>

void order_by_points(std::vector<int> &vec1, std::vector<int> &vec2) {
    std::string str;
    int *ptr1 = vec1.data();
    int *ptr2 = vec2.data();
    
    if (ptr1 == ptr2) return;

    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    for (size_t i = 0; i < size1; ++i) {
        for (size_t j = 0; j < size2; ++j) {
            if (ptr1[i] > ptr2[j]) {
                std::swap(ptr1[i], ptr2[j]);
            }
        }
    }

    // Placeholder for the string representation of a formatted output
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", std::abs(ptr1[0]));
    str.assign(buffer);
    std::cout << str << std::endl;
}

int main() {
    std::vector<int> vec1 = {3, 1, 2};
    std::vector<int> vec2 = {6, 5, 4};
    order_by_points(vec1, vec2);
    return 0;
}
```