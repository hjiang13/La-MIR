#include <string>
#include <algorithm>

int hex_key(const std::string& input) {
    std::string str = "2357BD";
    int count = 0;
    int index = 0;

    while (index < input.length()) {
        auto it = std::find(str.begin(), str.end(), input[index]);
        if (it != str.end()) {
            count++;
        }
        index++;
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
