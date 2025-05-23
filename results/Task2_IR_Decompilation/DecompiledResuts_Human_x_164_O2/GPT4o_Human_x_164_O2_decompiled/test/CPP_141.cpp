#include <string>
#include <cstring>

void file_name_check(std::string& output, const std::string& input) {
    if (input.size() < 5) {
        output = std::string(2, '\0');
        output[0] = (char)0x6F6E; // 'No'
        output[1] = '\0';
        return;
    }

    char first_char = input[0];
    if (first_char < 65) {
        output = std::string(2, '\0');
        output[0] = (char)0x6F6E; // 'No'
        output[1] = '\0';
        return;
    }

    if (first_char == 127 || first_char == 126 || first_char == 125 || first_char == 124 ||
        first_char == 123 || first_char == 96 || first_char == 95 || first_char == 94 ||
        first_char == 93 || first_char == 92 || first_char == 91) {
        output = std::string(2, '\0');
        output[0] = (char)0x6F6E; // 'No'
        output[1] = '\0';
        return;
    }

    std::string str1 = ".txt";
    std::string str2 = ".exe";
    std::string str3 = ".dll";

    if (input.compare(str1) == 0 || input.compare(str2) == 0 || input.compare(str3) == 0) {
        output = std::string(3, '\0');
        output[0] = 'Y';
        output[1] = 'e';
        output[2] = 's';
        output[3] = '\0';
    } else {
        output = std::string(2, '\0');
        output[0] = (char)0x6F6E; // 'No'
        output[1] = '\0';
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (file_name_check("example.txt") == "Yes");
    assert (file_name_check("1example.dll") == "No");
    assert (file_name_check("s1sdf3.asd") == "No");
    assert (file_name_check("K.dll") == "Yes");
    assert (file_name_check("MY16FILE3.exe") == "Yes");
    assert (file_name_check("His12FILE94.exe") == "No");
    assert (file_name_check("_Y.txt") == "No");
    assert (file_name_check("?aREYA.exe") == "No");
    assert (file_name_check("/this_is_valid.dll") == "No");
    assert (file_name_check("this_is_valid.wow") == "No");
    assert (file_name_check("this_is_valid.txt") == "Yes");
    assert (file_name_check("this_is_valid.txtexe") == "No");
    assert (file_name_check("#this2_i4s_5valid.ten") == "No");
    assert (file_name_check("@this1_is6_valid.exe") == "No");
    assert (file_name_check("this_is_12valid.6exe4.txt") == "No");
    assert (file_name_check("all.exe.txt") == "No");
    assert (file_name_check("I563_No.exe") == "Yes");
    assert (file_name_check("Is3youfault.txt") == "Yes");
    assert (file_name_check("no_one#knows.dll") == "Yes");
    assert (file_name_check("1I563_Yes3.exe") == "No");
    assert (file_name_check("I563_Yes3.txtt") == "No");
    assert (file_name_check("final..txt") == "No");
    assert (file_name_check("final132") == "No");
    assert (file_name_check("_f4indsartal132.") == "No");
    assert (file_name_check(".txt") == "No");
    assert (file_name_check("s.") == "No");
}
