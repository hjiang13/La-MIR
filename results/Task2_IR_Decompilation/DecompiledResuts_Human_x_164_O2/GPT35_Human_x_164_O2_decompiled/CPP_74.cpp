```cpp
#include <vector>
#include <string>

void total_match(std::vector<std::string>& result, std::vector<std::string>& input1, std::vector<std::string>& input2) {
    std::string* str1 = input1[0][0][0][1];
    std::string* str2 = input1[0][0][0][0];
    long long int diff = (long long int)str1 - (long long int)str2;
    if (diff == 0) {
        return;
    }
    long long int num_iterations = diff >> 5;
    num_iterations = std::max(num_iterations, 1LL);
    num_iterations--;
    int remainder = num_iterations & 3;
    bool less_than_3 = num_iterations < 3;
    if (less_than_3) {
        remainder = num_iterations & -4;
    }
    for (int i = 0; i < remainder; i++) {
        int offset = 0;
        for (int j = 0; j < 4; j++) {
            std::string* current_str = str2 + i;
            offset += *(long long int*)(current_str + 1);
        }
        result[0][0][0][0] += offset;
    }
}
```