```cpp
#include <string>
#include <cstdio>
#include <cstdarg>

int digits(int num) {
    std::__cxx11::basic_string<char> str;
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", num);
    str = buffer;
    
    int sum = 0;
    for (char c : str) {
        if (c >= '0' && c <= '9') {
            sum += c - '0';
        }
    }
    
    return sum;
}

int main() {
    int num = 12345;
    int result = digits(num);
    
    printf("Sum of digits in %d is %d\n", num, result);
    
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
