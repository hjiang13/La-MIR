#include <string>
#include <stdexcept>

void change_base(std::string& str, int base1, int base2) {
    std::allocator<char> alloc;
    std::string temp_str;
    
    if (base1 <= 0) {
        throw std::logic_error("basic_string::_M_construct null not valid");
    }
    
    if (base2 <= 0) {
        throw std::logic_error("basic_string::_M_construct null not valid");
    }
    
    int remainder = base1 % base2;
    temp_str = std::to_string(remainder);
    
    str = std::move(temp_str);
    
    int quotient = base1 / base2;
    while (quotient > 0) {
        remainder = quotient % base2;
        temp_str = std::to_string(remainder);
        str.append(temp_str);
        quotient /= base2;
    }
}

int main() {
    std::string result;
    change_base(result, 10, 2);
    return 0;
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
