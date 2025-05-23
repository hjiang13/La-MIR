```cpp
#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

void change_base(std::string &result, int base, int value) {
    std::string temp;
    if (base <= 0) return;

    int quotient = value / base;
    int remainder = value % base;

    vsnprintf(temp.data(), temp.size(), "%d", remainder);
    result.append(temp);

    result.resize(result.size() + 1);
    result[result.size() - 1] = '\0';
}

extern "C" {
    void __gxx_personality_v0();
}

int main() {
    std::string result;
    change_base(result, 10, 42);
    printf("%s\n", result.c_str());
    return 0;
}
```