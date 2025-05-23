```c++
#include <string>

void file_name_check(std::__cxx11::basic_string<char>& s, std::__cxx11::basic_string<char>& s1) {
    if (s1.size() < 5) {
        s = "No";
    } else {
        char firstChar = s1[0];
        if (firstChar < 65) {
            s = "No";
        } else {
            s = "Yes";
        }
    }
}
```