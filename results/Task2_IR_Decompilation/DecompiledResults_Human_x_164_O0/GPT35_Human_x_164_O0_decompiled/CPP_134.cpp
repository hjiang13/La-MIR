```c++
#include <string>

using namespace std;

bool check_if_last_char_is_a_letter(string* str) {
    bool result;
    if (str->length() == 0) {
        result = false;
    } else {
        char last_char = (*str)[str->length() - 1];
        if ((last_char < 65) || (last_char > 90 && last_char < 97) || (last_char > 122)) {
            result = false;
        } else {
            result = true;
        }
    }
    return result;
}
```