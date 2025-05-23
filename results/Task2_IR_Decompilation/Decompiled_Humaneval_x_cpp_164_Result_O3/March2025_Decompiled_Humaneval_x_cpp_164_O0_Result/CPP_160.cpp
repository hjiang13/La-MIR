```cpp
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>

int do_algebra(std::vector<std::string> &vec1, std::vector<int> &vec2) {
    std::vector<int> temp1;
    std::vector<int> temp2;

    for (int i = 0; i < vec2.size(); ++i) {
        temp2.push_back(i);
    }

    for (int i = 0; i < vec1.size(); ++i) {
        if (vec1[i] == "**") {
            int index = temp2[i];
            int base = temp2[index];
            int exp = temp2[base];
            int result = std::pow(vec2[base], vec2[exp]);
            vec2[temp2[index]] = result;
            temp2[index] = temp2[base];
        } else if (vec1[i] == "*") {
            int index = temp2[i];
            int a = vec2[temp2[index]];
            int b = vec2[temp2[index + 1]];
            vec2[temp2[index]] = a * b;
            temp2[index] = temp2[index + 1];
        } else if (vec1[i] == "/") {
            int index = temp2[i];
            int a = vec2[temp2[index]];
            int b = vec2[temp2[index + 1]];
            vec2[temp2[index]] = a / b;
            temp2[index] = temp2[index + 1];
        } else if (vec1[i] == "+") {
            int index = temp2[i];
            int a = vec2[temp2[index]];
            int b = vec2[temp2[index + 1]];
            vec2[temp2[index]] = a + b;
            temp2[index] = temp2[index + 1];
        } else if (vec1[i] == "-") {
            int index = temp2[i];
            int a = vec2[temp2[index]];
            int b = vec2[temp2[index + 1]];
            vec2[temp2[index]] = a - b;
            temp2[index] = temp2[index + 1];
        }
    }

    return vec2[0];
}
```