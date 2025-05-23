#include <string>
#include <iostream>

void fix_spaces(std::string& str, const std::string& input) {
    size_t count = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == ' ') {
            ++count;
        }
    }

    if (count == 0) {
        str = input;
        return;
    }

    str.resize(input.size() + count);
    size_t j = str.size() - 1;
    for (size_t i = input.size(); i-- > 0;) {
        if (input[i] == ' ') {
            str[j--] = ' ';
        } else {
            str[j--] = input[i];
        }
    }
}

int main() {
    std::string original = "This is a test string";
    std::string modified;
    fix_spaces(modified, original);
    std::cout << modified << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fix_spaces("Example") == "Example");
    assert (fix_spaces("Mudasir Hanif ") == "Mudasir_Hanif_");
    assert (fix_spaces("Yellow Yellow  Dirty  Fellow") == "Yellow_Yellow__Dirty__Fellow");
    assert (fix_spaces("Exa   mple") == "Exa-mple");
    assert (fix_spaces("   Exa 1 2 2 mple") == "-Exa_1_2_2_mple");
}
