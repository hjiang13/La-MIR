#include <string>
#include <vector>

std::string int_to_mini_romank(std::string& result, int num) {
    struct Roman {
        char symbol;
        int value;
    };
    
    std::vector<Roman> romanNumerals = {
        {'M', 1000}, {'CM', 900}, {'D', 500}, {'CD', 400},
        {'C', 100}, {'XC', 90}, {'L', 50}, {'XL', 40},
        {'X', 10}, {'IX', 9}, {'V', 5}, {'IV', 4}, {'I', 1}
    };

    for (const auto& r : romanNumerals) {
        while (num >= r.value) {
            result += r.symbol;
            num -= r.value;
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
