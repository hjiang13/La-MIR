```cpp
#include <string>

bool simplify(std::__cxx11::basic_string<char> &str1, std::__cxx11::basic_string<char> &str2) {
    if (str1.size() == 0) {
        return false;
    }

    int pos = 0;
    while (pos < str1.size() && str1[pos] == '/') {
        pos++;
    }

    if (pos == str1.size()) {
        return false;
    }

    std::__cxx11::basic_string<char> substr1 = str1.substr(pos);
    std::__cxx11::basic_string<char> substr2 = str2.substr(pos);

    if (substr1.size() > substr2.size()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::__cxx11::basic_string<char> str1 = "example/string/1";
    std::__cxx11::basic_string<char> str2 = "example/string/2";

    bool result = simplify(str1, str2);

    return 0;
}
```