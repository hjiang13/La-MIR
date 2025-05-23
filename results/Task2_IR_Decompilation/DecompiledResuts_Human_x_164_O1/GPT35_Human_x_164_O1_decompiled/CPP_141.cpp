```cpp
#include <iostream>
#include <string>

void file_name_check(std::__cxx11::basic_string<char>& sret, std::__cxx11::basic_string<char>& s) {
    if (s.size() < 5) {
        sret = ".No";
    } else {
        if (s[0] < 65) {
            sret = ".No";
        } else {
            sret = ".Yes";
        }
    }
}

int main() {
    std::__cxx11::basic_string<char> s1 = "filename.txt";
    std::__cxx11::basic_string<char> s2 = "filename.exe";
    std::__cxx11::basic_string<char> s3 = "filename.dll";
    
    std::__cxx11::basic_string<char> result;
    
    file_name_check(result, s1);
    std::cout << result << std::endl;
    
    file_name_check(result, s2);
    std::cout << result << std::endl;
    
    file_name_check(result, s3);
    std::cout << result << std::endl;
    
    return 0;
}
```