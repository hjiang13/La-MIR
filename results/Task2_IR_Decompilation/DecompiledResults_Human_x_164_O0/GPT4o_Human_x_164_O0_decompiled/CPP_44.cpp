```cpp
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
```