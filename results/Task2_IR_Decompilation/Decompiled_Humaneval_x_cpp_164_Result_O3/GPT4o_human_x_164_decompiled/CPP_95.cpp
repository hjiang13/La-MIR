```cpp
#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string> &dictionary) {
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
        const std::string &key = it->first;
        int count = 0;

        for (size_t i = 0; i < key.size(); ++i) {
            char c = key[i];
            if (c < 'A' || c > 'z') {
                continue;
            }
            if (c >= 'A' && c <= 'Z') {
                c += 32; // Convert to lowercase
            }
            if (c >= 'a' && c <= 'z') {
                if (++count > 2) {
                    return false;
                }
            }
        }

        if (count != 2) {
            return false;
        }
    }
    return true;
}
```