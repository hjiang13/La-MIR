```cpp
#include <string>
#include <vector>
#include <cstring>

void Strongest_Extension(std::string &result, const std::string &input, const std::vector<std::string> &vec) {
    std::string temp1;
    std::string temp2;

    if (&input == &vec[0] || &input == &vec[1]) {
        return;
    }

    for (const auto &s : vec) {
        if (s.empty()) {
            continue;
        }

        size_t len = s.length();
        const char *data = s.data();

        for (size_t i = 0; i < len; ++i) {
            char c = data[i];
            if (c >= 'A' && c < 'A' + 26) {
                ++temp1[static_cast<unsigned char>(c) - 'A'];
            }
            if (c >= 'a' && c < 'a' + 26) {
                ++temp2[static_cast<unsigned char>(c) - 'a'];
            }
        }
    }

    result.append(temp1);
    result.append(temp2);
}
```