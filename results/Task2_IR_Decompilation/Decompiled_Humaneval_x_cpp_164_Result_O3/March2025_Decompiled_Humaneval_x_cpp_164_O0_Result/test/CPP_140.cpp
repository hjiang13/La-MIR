#include <string>

std::string fix_spaces(const std::string& input) {
    std::string result;
    int space_count = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char current_char = input[i];
        if (current_char == ' ') {
            ++space_count;
        } else {
            if (space_count == 1) {
                result += '_';
            } else if (space_count == 2) {
                result += "__";
            } else if (space_count > 2) {
                result += "-";
            }
            result += current_char;
            space_count = 0;
        }
    }

    if (space_count == 1) {
        result += '_';
    } else if (space_count == 2) {
        result += "__";
    } else if (space_count > 2) {
        result += "-";
    }

    return result;
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
