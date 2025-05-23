```cpp
#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string> &m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        const std::string &key = it->first;
        bool has_upper = false;
        bool has_lower = false;

        for (char c : key) {
            if (c >= 'A' && c <= 'Z') {
                has_upper = true;
            } else if (c >= 'a' && c <= 'z') {
                has_lower = true;
            }

            if (has_upper && has_lower) {
                return false;
            }
        }
    }
    return true;
}
```