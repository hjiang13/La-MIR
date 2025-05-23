```cpp
#include <string>
#include <cstdio>

void change_baseB5cxx11(std::__cxx11::basic_string* s, int num1, int num2) {
    std::__cxx11::basic_string s1;
    std::__cxx11::basic_string s2;
    
    int remainder = num1 % num2;
    int quotient = num1 / num2;
    
    char buffer[3];
    snprintf(buffer, 3, "%d", remainder);
    
    s2.append(buffer);

    s->clear();
    s->append(s2);
}

int main() {
    std::__cxx11::basic_string str;
    change_baseB5cxx11(&str, 10, 2);
    return 0;
}
```