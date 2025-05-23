#include <string>
#include <cstring>
#include <stdexcept>

void fix_spaces(std::string& s) {
    std::string tmp;
    size_t length = s.length();
    size_t space_count = 0;

    for (size_t i = 0; i < length; ++i) {
        if (s[i] == ' ') {
            space_count++;
        } else {
            if (space_count > 0) {
                tmp += ' ';
                space_count = 0;
            }
            tmp += s[i];
        }
    }

    if (space_count > 0) {
        tmp += ' ';
    }

    s = tmp;
}

int main() {
    std::string test = "This    is   a   test   string.";
    fix_spaces(test);
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
