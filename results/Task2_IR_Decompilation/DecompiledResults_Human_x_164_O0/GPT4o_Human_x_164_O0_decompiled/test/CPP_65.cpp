#include <iostream>
#include <string>
#include <iterator>

std::string circular_shift(int a, int b) {
    std::string result;
    std::string str = std::to_string(a);
    int len = str.length();
    b = b % len; // Normalize b to be within the string length

    if (b < 0) {
        b += len; // Handle negative shifts
    }

    result = str.substr(len - b) + str.substr(0, len - b);
    return result;
}

int main() {
    int a = 12345;
    int b = 2;
    std::string shifted = circular_shift(a, b);
    std::cout << shifted << std::endl; // Output: 45123
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (circular_shift(100, 2) == "001");
    assert (circular_shift(12, 2) == "12");
    assert (circular_shift(97, 8) == "79");
    assert (circular_shift(12, 1) == "21");
    assert (circular_shift(11, 101) == "11");
}
