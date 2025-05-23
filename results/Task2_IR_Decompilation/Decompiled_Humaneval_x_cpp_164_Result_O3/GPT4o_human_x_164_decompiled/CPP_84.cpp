```cpp
#include <string>
#include <cstdarg>
#include <cstdio>

void solve(std::string &result, int count, ...) {
    std::string temp;
    va_list args;
    va_start(args, count);
    char buffer[32];
    vsnprintf(buffer, sizeof(buffer), "%d", count);
    temp.append(buffer);
    va_end(args);
    
    result = temp;
}

int main() {
    std::string output;
    solve(output, 5);
    printf("%s\n", output.c_str());
    return 0;
}
```