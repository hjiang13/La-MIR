```cpp
#include <string>

bool correct_bracketing(std::__cxx11::basic_string<char>* str) {
    i64 size = str->size;
    if(size == 0) {
        return true;
    }

    i8* data = str->data;
    i64 index = 0;
    i32 count = 0;

    while(index < size) {
        i8 current_char = data[index];
        i32 open_bracket = (current_char == 40) ? 1 : 0;
        count += open_bracket;
        i32 close_bracket = (current_char == 41) ? 1 : 0;
        count += close_bracket;
        if(count < 0) {
            return false;
        }
        index++;
    }

    return count == 0;
}
```