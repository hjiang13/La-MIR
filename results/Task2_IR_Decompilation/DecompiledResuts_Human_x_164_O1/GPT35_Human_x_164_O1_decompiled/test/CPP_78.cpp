```cpp
#include <string>

int hex_key(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>* param) {
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> str = "2357BD";
    int count = 0;
    
    if (param->size() == 0) {
        return count;
    }
    
    for (int i = 0; i < param->size(); i++) {
        if (param->at(i) == str[count % str.size()]) {
            count++;
        }
    }
    
    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (hex_key("AB") == 1      );
    assert (hex_key("1077E") == 2 );
    assert (hex_key("ABED1A33") == 4     );
    assert (hex_key("2020") == 2 );
    assert (hex_key("123456789ABCDEF0") == 6      );
    assert (hex_key("112233445566778899AABBCCDDEEFF00") == 12 );
    assert (hex_key("") == 0);
}
