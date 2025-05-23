```cpp
#include <string>
#include <cstdarg>
#include <cstdio>

void change_base(std::string& result, int base, int number) {
    std::string buffer;
    int remainder;
    if (base <= 0) return;

    do {
        remainder = number % base;
        number /= base;
        buffer.insert(buffer.begin(), '0' + remainder);
    } while (number != 0);

    result.append(buffer);
}

int main() {
    std::string result;
    change_base(result, 10, 255);
    printf("%s\n", result.c_str());
    return 0;
}
```