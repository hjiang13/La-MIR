#include <iostream>
#include <string>

int hex_key(std::basic_string<char> str) {
    const char* key = "2357BD";
    
    if (str.size() == 0) {
        return 0;
    }
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != key[i % 6]) {
            return i;
        }
    }
    
    return 0;
}

int main() {
    std::string input = "2357BD";
    int result = hex_key(input);
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
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
