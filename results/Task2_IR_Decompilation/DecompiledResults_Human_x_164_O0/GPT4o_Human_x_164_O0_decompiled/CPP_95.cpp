```cpp
#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string>& dict) {
    if (dict.size() == 0) return false;

    auto it = dict.begin();
    auto end = dict.end();
    bool isValid = true;

    while (it != end) {
        char c = it->first[0];

        if (c < 'A' || c > 'z' || (c > 'Z' && c < 'a')) {
            isValid = false;
            break;
        }

        ++it;
    }

    return isValid;
}
```