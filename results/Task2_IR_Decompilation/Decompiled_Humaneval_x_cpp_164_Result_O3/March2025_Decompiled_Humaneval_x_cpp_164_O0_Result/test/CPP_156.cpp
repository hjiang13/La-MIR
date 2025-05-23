#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>

std::string int_to_mini_roman(int num) {
    std::vector<std::string> roman_literals = {"m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};
    std::vector<int> roman_values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    std::string result;
    for (size_t i = 0; i < roman_values.size(); ++i) {
        while (num >= roman_values[i]) {
            result += roman_literals[i];
            num -= roman_values[i];
        }
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (int_to_mini_romank(19) == "xix");
    assert (int_to_mini_romank(152) == "clii");
    assert (int_to_mini_romank(251) == "ccli");
    assert (int_to_mini_romank(426) == "cdxxvi");
    assert (int_to_mini_romank(500) == "d");
    assert (int_to_mini_romank(1) == "i");
    assert (int_to_mini_romank(4) == "iv");
    assert (int_to_mini_romank(43) == "xliii");
    assert (int_to_mini_romank(90) == "xc");
    assert (int_to_mini_romank(94) == "xciv");
    assert (int_to_mini_romank(532) == "dxxxii");
    assert (int_to_mini_romank(900) == "cm");
    assert (int_to_mini_romank(994) == "cmxciv");
    assert (int_to_mini_romank(1000) == "m");
}
