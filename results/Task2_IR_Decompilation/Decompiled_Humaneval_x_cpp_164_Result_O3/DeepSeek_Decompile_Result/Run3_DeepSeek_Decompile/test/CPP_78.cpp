#include <string>

int hex_key(const std::string& input) {
    const char* hex_string = "2357BD";
    int count = 0;
    size_t input_length = input.length();

    if (input_length == 0) {
        return 0;
    }

    for (size_t i = 0; i < 6 && i < input_length; ++i) {
        if (input[i] != hex_string[i]) {
            break;
        }
        count++;
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
