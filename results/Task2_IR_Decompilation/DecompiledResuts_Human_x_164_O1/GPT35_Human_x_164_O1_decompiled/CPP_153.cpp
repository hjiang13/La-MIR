```cpp
#include <string>
#include <vector>

void Strongest_Extension(std::string& result, const std::string& input, const std::vector<std::string>& vec) {
    std::string temp;
    
    if (vec.size() > 15) {
        temp = input;
    } else {
        temp = vec[0];
    }
    
    result = temp;
    
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] >= 'a' && temp[i] <= 'z') {
            result[i] = temp[i] - 32; // Convert to uppercase
        } else if (temp[i] >= 'A' && temp[i] <= 'Z') {
            result[i] = temp[i] + 32; // Convert to lowercase
        }
    }
}
```