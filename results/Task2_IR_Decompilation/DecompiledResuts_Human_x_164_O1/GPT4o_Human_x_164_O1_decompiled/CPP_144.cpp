```cpp
#include <string>
#include <cstdlib>
#include <stdexcept>

bool simplify(std::string s1, std::string s2) {
    int pos1 = 0, pos2 = 0;
    while (true) {
        if (pos1 >= s1.size()) {
            if (pos2 >= s2.size()) {
                return true;
            }
            return false;
        }
        if (pos2 >= s2.size()) {
            return false;
        }
        if (s1[pos1] == '/') {
            pos1++;
            continue;
        }
        if (s2[pos2] == '/') {
            pos2++;
            continue;
        }
        if (s1[pos1] == s2[pos2]) {
            pos1++;
            pos2++;
            continue;
        }
        return false;
    }
}
```