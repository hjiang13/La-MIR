#include <string>
#include <vector>

void int_to_mini_romank(std::string& result, int num) {
    struct StringData {
        std::string* data;
        size_t size;
    };

    std::vector<StringData> strings(13);
    strings[0] = {new std::string("M"), 1}; // 1000
    strings[1] = {new std::string("CM"), 2}; // 900
    strings[2] = {new std::string("D"), 1}; // 500
    strings[3] = {new std::string("CD"), 2}; // 400
    strings[4] = {new std::string("C"), 1}; // 100
    strings[5] = {new std::string("XC"), 2}; // 90
    strings[6] = {new std::string("L"), 1}; // 50
    strings[7] = {new std::string("XL"), 2}; // 40
    strings[8] = {new std::string("X"), 1}; // 10
    strings[9] = {new std::string("IX"), 2}; // 9
    strings[10] = {new std::string("V"), 1}; // 5
    strings[11] = {new std::string("IV"), 2}; // 4
    strings[12] = {new std::string("I"), 1}; // 1

    for (int i = 0; i < 13 && num > 0; ++i) {
        while (num >= (i < 13 ? (i == 0 ? 1000 : (i == 1 ? 900 : (i == 2 ? 500 : (i == 3 ? 400 : (i == 4 ? 100 : (i == 5 ? 90 : (i == 6 ? 50 : (i == 7 ? 40 : (i == 8 ? 10 : (i == 9 ? 9 : (i == 10 ? 5 : (i == 11 ? 4 : 1)))))))))))))) {
            result += *strings[i].data;
            num -= (i == 0 ? 1000 : (i == 1 ? 900 : (i == 2 ? 500 : (i == 3 ? 400 : (i == 4 ? 100 : (i == 5 ? 90 : (i == 6 ? 50 : (i == 7 ? 40 : (i == 8 ? 10 : (i == 9 ? 9 : (i == 10 ? 5 : (i == 11 ? 4 : 1))))))))))))));
        }
    }

    for (auto& str : strings) {
        delete str.data;
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
