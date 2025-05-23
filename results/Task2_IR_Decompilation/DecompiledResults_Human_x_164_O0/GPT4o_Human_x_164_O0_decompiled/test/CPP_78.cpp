#include <iostream>
#include <string>
#include <algorithm>

int hex_key(const std::string& str) {
    std::string hex_string = "2357BD";
    int count = 0;
    auto it = str.begin();
    auto end = str.end();

    while (it != end) {
        auto found = std::find(it, end, *hex_string.begin());
        if (found != end) {
            ++count;
            it = found + 1;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    std::string test_string = "Your input string here";
    int result = hex_key(test_string);
    std::cout << result << std::endl;
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
