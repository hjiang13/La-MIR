```c++
#include <string>
#include <vector>

void concatenate(std::string& result, std::vector<std::string>& input) {
    std::string temp;
    
    for (const std::string& str : input) {
        temp.append(str);
    }
    
    result = temp;
}
```