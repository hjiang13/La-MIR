```cpp
#include <string>

bool simplify(std::basic_string<char> *str1, std::basic_string<char> *str2) {
    if (str1->size() == 0)
        return false;

    int pos = 0;
    char *substr = &(*str1)[pos];

    if (*substr == '/')
        return false;

    int len = str1->size() - pos;
    std::basic_string<char> tmp = str1->substr(pos, len);
    *str2 = tmp;

    return true;
}

int main() {
    std::basic_string<char> str1 = "basic_string::substr";
    std::basic_string<char> str2;

    if (simplify(&str1, &str2)) {
        // Do something with simplified string
    }

    return 0;
}
```