```cpp
#include <string>
#include <cstdlib>

int fruit_distribution(std::basic_string<char> &str, int num) {
    std::__cxx11::basic_string<char> str1;
    std::__cxx11::basic_string<char> str2;
    std::__cxx11::basic_string<char> str3;
    std::__cxx11::basic_string<char> str4;

    if (str1.empty()) {
        return num;
    }

    int val1 = std::strtol(&str[0], nullptr, 10);
    int val2 = std::strtol(&str[0], nullptr, 10);

    if (&str[0] == nullptr) {
        std::free(&str[0]);
    }

    if (str1.empty()) {
        std::free(&str1[0]);
    }

    int result = val1 + val2;
    int remaining = num - result;

    return remaining;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fruit_distribution("5 apples and 6 oranges",19) == 8);
    assert (fruit_distribution("5 apples and 6 oranges",21) == 10);
    assert (fruit_distribution("0 apples and 1 oranges",3) == 2);
    assert (fruit_distribution("1 apples and 0 oranges",3) == 2);
    assert (fruit_distribution("2 apples and 3 oranges",100) == 95);
    assert (fruit_distribution("2 apples and 3 oranges",5) == 0);
    assert (fruit_distribution("1 apples and 100 oranges",120) == 19);
}
