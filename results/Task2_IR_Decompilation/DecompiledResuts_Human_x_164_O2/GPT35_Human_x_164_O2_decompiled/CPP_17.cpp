```cpp
#include <vector>
#include <string>

void parse_music(std::vector<int>& vec, std::__cxx11::basic_string<char>& str) {
    std::__cxx11::basic_string<char> temp_str;
    
    if (str.size() == 0) {
        return;
    }
    
    for (char c : str) {
        temp_str.push_back(c);
    }
    
    vec.clear();
    
    for (int i = 0; i < temp_str.size(); i++) {
        vec.push_back(temp_str[i]);
    }
}
```