```c++
#include <string>
#include <cstdio>

std::__cxx11::basic_string<char> decimal_to_binary(int num) {
    std::__cxx11::basic_string<char> result;

    if (num == 0) {
        result = "0";
    } else {
        while (num > 0) {
            if (num % 2 == 0) {
                result = "0" + result;
            } else {
                result = "1" + result;
            }
            num /= 2;
        }
    }

    return result;
}

int main() {
    int decimal_number = 10;
    std::__cxx11::basic_string<char> binary_number = decimal_to_binary(decimal_number);

    printf("Decimal number: %d\n", decimal_number);
    printf("Binary number: %s\n", binary_number.c_str());

    return 0;
}
```