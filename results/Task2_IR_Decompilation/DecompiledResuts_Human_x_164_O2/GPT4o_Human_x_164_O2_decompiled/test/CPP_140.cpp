#include <string>
#include <cstring>

void fix_spaces(std::string& s) {
    size_t len = s.length();
    if (len == 0) {
        return;
    }

    std::string result;
    result.reserve(len);

    size_t space_count = 0;
    for (size_t i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            if (space_count == 0) {
                result += ' ';
            }
            space_count++;
        } else {
            result += s[i];
            space_count = 0;
        }
    }

    s = result;
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
