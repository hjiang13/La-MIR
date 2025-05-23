#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> int_to_mini_romank(int num) {
    std::vector<std::string> romanNumerals = {
        "m", "cm", "cd", "d", "xc", "xl", "x", "ix", "v", "iv", "i"
    };

    std::vector<int> values = {
        1000, 900, 400, 500, 90, 40, 10, 9, 5, 4, 1
    };

    std::string result;
    for (size_t i = 0; i < values.size(); ++i) {
        while (num >= values[i]) {
            result += romanNumerals[i];
            num -= values[i];
        }
    }
    return result;
}

int main() {
    int number = 1994;
    std::string roman = int_to_mini_romank(number);
    std::cout << "Roman numeral: " << roman << std::endl;
    return 0;
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
