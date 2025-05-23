```cpp
#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string> *dict) {
    if (dict->empty()) {
        return true;
    }

    auto it = dict->begin();
    auto node = it->second;
    std::string str;
    str.reserve(node.size());

    for (auto c : node) {
        if (c < 'A' || c > 'Z') {
            return true;
        }

        str.push_back(c - 'A' + 'a');
    }

    dict->begin()->second = str;

    return false;
}
```