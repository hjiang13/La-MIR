```c
#include <string>

void string_xor(std::__cxx11::basic_string<char>& result, std::__cxx11::basic_string<char>& str1, std::__cxx11::basic_string<char>& str2) {
    result = "";
    int index = 0;

    while (index < str1.length() && index < str2.length()) {
        char char1 = str1[index];
        char char2 = str2[index];

        if (char1 == char2) {
            result.push_back(char1 ^ 48);
        } else {
            result.push_back(char2);
        }

        index++;
    }
}

int main() {
    std::__cxx11::basic_string<char> str1 = "input_string_1";
    std::__cxx11::basic_string<char> str2 = "input_string_2";
    std::__cxx11::basic_string<char> result;

    string_xor(result, str1, str2);

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
