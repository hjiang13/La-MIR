```cpp
#include <string>

int is_bored(std::basic_string<char> *str) {
    char flag1 = 1;
    char flag2 = 0;
    int count1 = 0;
    int count2 = 0;

    while (count2 < static_cast<int>(str->length())) {
        char current_char = (*str)[count2];
        int char_val = static_cast<int>(current_char);

        if (char_val == 32) {
            if (flag2) {
                flag2 = 0;
            }
            else {
                flag2 = 1;
                count1++;
            }
        }

        if (char_val == 73) {
            if (flag1) {
                flag1 = 0;
            }
            else {
                flag1 = 1;
            }
        }

        if (char_val != 32) {
            flag2 = 0;
        }

        if (char_val == 46) {
            break;
        }

        if (char_val == 63) {
            break;
        }

        if (char_val == 33) {
            break;
        }

        count2++;
    }

    return count1;
}
```