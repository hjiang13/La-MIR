#include <string>
#include <cstring>

int hex_key(const std::string& input) {
    std::string temp;
    const char* str = "2357BD";
    temp.assign(str, 6);

    if (input.empty()) {
        return 0;
    }

    const char* input_data = input.data();
    size_t input_size = input.size();
    int count = 0;

    for (size_t i = 0; i < input_size; ++i) {
        if (i < 4) {
            if (temp[i] != input_data[i]) {
                break;
            }
        } else {
            if (temp[i - 4] != input_data[i]) {
                break;
            }
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
