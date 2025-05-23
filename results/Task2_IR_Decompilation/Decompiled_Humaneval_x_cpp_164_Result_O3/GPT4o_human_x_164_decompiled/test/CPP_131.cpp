#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <string>

int digitsi(int num) {
    std::string str;
    char buffer[3]; // buffer to hold the string representation (max 2 digits + null terminator)
    int length = snprintf(buffer, sizeof(buffer), "%d", num);
    
    if (length == 0) {
        return 0;
    }
    
    for (int i = 0; i < length; ++i) {
        char ch = buffer[i];
        if (ch % 2 == 1) {
            str += (ch - '0') + 1; // Increment odd digits
        } else {
            str += (ch - '0'); // Keep even digits as is
        }
    }

    return str.length(); // return the length of the string
}

int main() {
    int result = digitsi(42);
    printf("Result: %d\n", result);
    return 0;
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
