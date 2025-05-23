#include <string>
#include <cstring>

int hex_key(std::string str) {
    std::string tmp = "2357BD";
    int count = 0;
    size_t length = str.length();
    
    if (length == 0) {
        return count;
    }

    for (size_t i = 0; i < length; ++i) {
        if (i < tmp.length() && str[i] == tmp[i]) {
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
