```cpp
#include <string>
#include <iterator>

template <typename _CharT, typename _Traits, typename _Alloc>
bool same_chars(std::basic_string<_CharT, _Traits, _Alloc>& str1, std::basic_string<_CharT, _Traits, _Alloc>& str2) {
    int i = 0;
    for (; i < str1.length() && i < str2.length(); ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return i == str1.length() && i == str2.length();
}
```