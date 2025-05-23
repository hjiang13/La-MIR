#include <string>
#include <vector>

std::vector<std::string> constinit = {
    "M", "CM", "D", "C", "X", "IX", "V", "IV", "I", "II", "III", "VI", "VII", "VIII"
};

void int_to_mini_romank(std::string &result, int num) {
    std::vector<std::string> roman_numerals;
    roman_numerals.reserve(13);
    roman_numerals.push_back("M");
    roman_numerals.push_back("CM");
    roman_numerals.push_back("D");
    roman_numerals.push_back("C");
    roman_numerals.push_back("X");
    roman_numerals.push_back("IX");
    roman_numerals.push_back("V");
    roman_numerals.push_back("IV");
    roman_numerals.push_back("I");
    roman_numerals.push_back("II");
    roman_numerals.push_back("III");
    roman_numerals.push_back("VI");
    roman_numerals.push_back("VII");
    roman_numerals.push_back("VIII");

    if (num <= 0) {
        result = "";
        return;
    }

    for (int i = 0; num > 0; i++) {
        while (num >= constinit[i]) {
            result += roman_numerals[i];
            num -= constinit[i];
        }
    }
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
