#include <string>

void fix_spaces(std::string& dest, std::string& source) {
    dest = "";
    int i = 0;
    int length = source.length();
    
    while (i < length) {
        char c = source[i];
        
        if (c == ' ') {
            int count = 0;
            while (i < length && source[i] == ' ') {
                count++;
                i++;
            }
            
            if (count == 1) {
                dest += "__";
            } else if (count == 2) {
                dest += "_";
            } else {
                dest += " ";
            }
        } else {
            dest += c;
            i++;
        }
    }
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
