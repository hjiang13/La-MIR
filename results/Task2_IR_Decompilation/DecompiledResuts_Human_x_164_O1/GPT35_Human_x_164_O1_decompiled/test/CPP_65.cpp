```cpp
#include <string>
#include <cstdio>

void circular_shift(std::string& s, int num1, int num2) {
    if (num1 == 0 || num2 == 0) {
        return;
    }

    int len = s.length();
    num2 = num2 % len;

    if (num2 == 0) {
        return;
    }

    std::string temp = s.substr(len - num2, num2);
    s.erase(len - num2);
    s = temp + s;
}

int main() {
    std::string input = "Hello, World!";
    int num1 = 3;
    int num2 = 5;

    circular_shift(input, num1, num2);

    printf("%s\n", input.c_str());

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (circular_shift(100, 2) == "001");
    assert (circular_shift(12, 2) == "12");
    assert (circular_shift(97, 8) == "79");
    assert (circular_shift(12, 1) == "21");
    assert (circular_shift(11, 101) == "11");
}
