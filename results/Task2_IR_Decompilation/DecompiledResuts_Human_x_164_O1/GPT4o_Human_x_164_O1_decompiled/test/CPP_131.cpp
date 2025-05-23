#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <string>

int digitsi(int num) {
    std::string str;
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", num);
    str = buffer;

    int result = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];
        int value = (ch - '0') % 2 == 1 ? (ch - '0' - 48) : 1;
        result += value;
    }
    return result;
}

extern "C" {
    void vsnprintf(char *str, size_t size, const char *format, ...);
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (digits(5) == 5);
    assert (digits(54) == 5);
    assert (digits(120) ==1);
    assert (digits(5014) == 5);
    assert (digits(98765) == 315);
    assert (digits(5576543) == 2625);
    assert (digits(2468) == 0);
}
