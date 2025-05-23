```c
#include <string>
#include <cstring>

void decimal_to_binary(std::string& s, int num) {
    if (num == 0) {
        s = "db0db";
    } else {
        int rem = num % 2;
        int quot = num / 2;
        
        char buffer[3];
        snprintf(buffer, 3, "%d", rem);
        s.append(buffer);
        
        decimal_to_binary(s, quot);
    }
}
```