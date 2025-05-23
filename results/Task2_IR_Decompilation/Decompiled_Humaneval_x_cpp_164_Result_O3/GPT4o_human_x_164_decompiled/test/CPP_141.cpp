#include <string>
#include <iostream>

void file_name_check(std::string& output, const std::string& input) {
    if (input.size() < 5) {
        output = std::string(2, '\0');
        output[0] = 0x6e; // 'n'
        output[1] = 0x6f; // 'o'
        return;
    }

    char firstChar = input[0];
    if (firstChar < 65) {
        switch (firstChar) {
            case 127:
            case 126:
            case 125:
            case 124:
            case 123:
            case 96:
            case 95:
            case 94:
            case 93:
            case 92:
            case 91:
                output = std::string(2, '\0');
                output[0] = 0x6e; // 'n'
                output[1] = 0x6f; // 'o'
                return;
        }
    }

    std::string target;
    target.reserve(32);
    target.assign(input, 0, input.size() - 4);

    if (target.compare(".txt") == 0) {
        output.assign("No", 2);
        return;
    } else if (target.compare(".exe") == 0) {
        output.assign("No", 2);
        return;
    } else if (target.compare(".dll") == 0) {
        output.assign("No", 2);
        return;
    }

    output.assign("Yes", 3);
}

int main() {
    std::string result;
    std::string fileName = "example.txt"; // Example filename for testing
    file_name_check(result, fileName);
    std::cout << result << std::endl;
    return 0;
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
