#include <string>
#include <stdexcept>

std::string change_base(int num, int base) {
    if (base <= 0) {
        throw std::logic_error("basic_string::_M_construct null not valid");
    }
    std::string result;
    while (num > 0) {
        int remainder = num % base;
        result = std::to_string(remainder) + result;
        num /= base;
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (change_base(8, 3) == "22");
    assert (change_base(9, 3) == "100");
    assert (change_base(234, 2) == "11101010");
    assert (change_base(16, 2) == "10000");
    assert (change_base(8, 2) == "1000");
    assert (change_base(7, 2) == "111");
    for (int x=2;x<8;x++)
        assert (change_base(x, x + 1) == to_string(x));
}
