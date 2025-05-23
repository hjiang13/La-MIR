#include <cstdarg>
#include <cstdio>
#include <string>

int digitsi(int num) {
    std::string result;
    char buffer[3];
    int length = snprintf(buffer, sizeof(buffer), "%d", num);

    if (length == 0) {
        return 1;
    }

    for (int i = 0; i < length; ++i) {
        if (buffer[i] % 2 == 1) {
            result += (buffer[i] - '0') + 1;
        } else {
            result += (buffer[i] - '0');
        }
    }

    return result.empty() ? 0 : result.length();
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
