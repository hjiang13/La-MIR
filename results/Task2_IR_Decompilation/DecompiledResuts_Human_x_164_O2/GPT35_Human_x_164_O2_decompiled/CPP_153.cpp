```cpp
#include <string>
#include <vector>

void Strongest_Extension(std::string& result, const std::string& input, const std::vector<std::string>& vec) {
    std::__cxx11::basic_string<char> s;
    std::__cxx11::basic_string<char> s_temp;
    
    for (const auto& str : vec) {
        if (s_temp == str) {
            // do something
        } else {
            s_temp = str;
            int count = 0;
            int offset = -1000;
            for (size_t i = 0; i < s_temp.size(); i++) {
                char c = s_temp[i];
                if (c >= 'a' && c <= 'z') {
                    // do something
                }
            }
        }
    }
    
    result = s;
}

int main() {
    std::string result;
    std::string input;
    std::vector<std::string> vec;
    
    Strongest_Extension(result, input, vec);
    
    return 0;
}
```