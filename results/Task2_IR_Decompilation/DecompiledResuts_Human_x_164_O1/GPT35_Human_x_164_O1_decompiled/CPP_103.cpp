```c
#include <string>
#include <cstdio>
#include <cstdarg>

void rounded_avg(std::string& s, int a, int b) {
    if (a > b) {
        s = std::to_string((a + b) / 2);
    } else {
        s = std::to_string((a + b) / 2);
    }
}

int main() {
    std::string result;
    rounded_avg(result, 10, 20);
    printf("%s\n", result.c_str());
    return 0;
}
```