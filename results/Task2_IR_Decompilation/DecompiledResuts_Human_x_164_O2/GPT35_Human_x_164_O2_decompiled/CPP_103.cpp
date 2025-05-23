```cpp
#include <string>
#include <cstdio>

void rounded_avg(std::string& s, int a, int b) {
    if (a > b) {
        s = "%d";
        s[2] = '\0';
    } else {
        std::string s1;
        s1 = "";
        s1.append(s, a, b);
    }
}

int main() {
    std::string s;
    int a = 10;
    int b = 20;
    rounded_avg(s, a, b);
    return 0;
}
```