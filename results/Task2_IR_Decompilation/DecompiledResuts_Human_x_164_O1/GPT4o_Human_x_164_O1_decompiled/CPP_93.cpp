```cpp
#include <string>
#include <cstring>

void encode(std::string& dest, const std::string& src) {
    const char* vowels = "aeiouAEIOU";
    std::string temp(10, '\0');
    std::size_t length = src.length();
    std::size_t count = 0;

    for (std::size_t i = 0; i < length; ++i) {
        char c = src[i];
        char encoded_char = c - 97;

        if (encoded_char < 26) {
            temp[count++] = c - 32;
        } else {
            encoded_char = c - 65;
            if (encoded_char < 26) {
                temp[count++] = c + 32;
            } else {
                temp[count++] = c;
            }
        }
    }

    if (count > 3) {
        std::string new_string(count + 1, '\0');
        std::memcpy(&new_string[0], &temp[0], count);
        new_string[count] = '\0';
        dest = new_string;
    } else {
        dest = src;
    }
}
```