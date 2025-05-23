#include <string>
#include <iostream>

void fix_spaces(std::string &input) {
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == ' ') {
            result += (i > 0 && input[i - 1] != ' ') ? ' ' : '\0';
        } else {
            result += input[i];
        }
    }
    input = result;
}

int main() {
    std::string str = " Hello   World! ";
    fix_spaces(str);
    std::cout << "'" << str << "'" << std::endl;
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
