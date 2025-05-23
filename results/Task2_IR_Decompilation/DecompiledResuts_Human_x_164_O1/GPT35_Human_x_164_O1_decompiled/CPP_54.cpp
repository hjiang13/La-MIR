```c++
#include <string>

bool same_chars(std::basic_string<char>* str1, std::basic_string<char>* str2) {
    if (str1->size() == 0) {
        return false;
    }

    if (str1->size() > 3) {
        return str1->size() == str2->size();
    }

    for (size_t i = 0; i < str1->size(); ++i) {
        if ((*str1)[i] != (*str2)[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::basic_string<char> str1 = "hello";
    std::basic_string<char> str2 = "hello";

    if (same_chars(&str1, &str2)) {
        return 1;
    } else {
        return 0;
    }
}
```