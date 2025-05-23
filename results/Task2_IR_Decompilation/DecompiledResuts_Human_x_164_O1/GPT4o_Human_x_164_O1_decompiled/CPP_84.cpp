```cpp
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <string>

void solve(std::string &result, int value) {
    std::string buffer;
    int length = snprintf(buffer.data(), 16, "%d", value);

    if (length > 0) {
        result = buffer;
    } else {
        result.clear();
    }
}

int main() {
    std::string output;
    int value = 42;
    solve(output, value);
    printf("Result: %s\n", output.c_str());
    return 0;
}
```