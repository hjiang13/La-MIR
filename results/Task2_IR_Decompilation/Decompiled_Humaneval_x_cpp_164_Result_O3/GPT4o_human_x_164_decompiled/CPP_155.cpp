```cpp
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>
#include <cstdlib>
#include <cstdio>

void even_odd_count(std::vector<int>& result, int num) {
    std::string str;
    int abs_num = abs(num);
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", abs_num);
    str = buffer;

    size_t length = str.size();
    if (length == 0) {
        result = {0, 0};
        return;
    }

    result.resize(2, 0);
    for (size_t i = 0; i < length; ++i) {
        char ch = str[i];
        if (ch % 2 == 0) {
            result[0]++;
        } else {
            result[1]++;
        }
    }
}
```