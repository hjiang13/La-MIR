```c
#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string>& dict) {
    if (dict.empty()) {
        return false;
    } else {
        auto it = dict.begin();
        std::string key = it->first;
        std::string value = it->second;

        if (value.size() > 15) {
            key = std::string(value.begin(), value.begin() + 16);
            value = std::string(value.begin() + 16, value.end());
        }

        for (char& c : value) {
            if (c < 'A' || c > 'Z') {
                return false;
            }
        }

        return true;
    }
}
```