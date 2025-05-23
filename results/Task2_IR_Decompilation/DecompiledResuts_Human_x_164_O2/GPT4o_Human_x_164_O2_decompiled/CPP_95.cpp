```cpp
#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string> &dict) {
    int count = 0;
    bool result = false;
    std::string str;

    for (auto it = dict.begin(); it != dict.end(); ++it) {
        str = it->second;
        for (size_t i = 0; i < str.size(); ++i) {
            char ch = str[i];
            if (ch < 65) {
                result = false;
                break;
            }
            if (ch > 90) {
                result = false;
                break;
            }
            count++;
            if (count == 2) {
                result = true;
                break;
            }
        }
        if (result) break;
    }
    return result;
}
```