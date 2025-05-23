#include <string>

void solve(std::string& result, const std::string& input) {
    result.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        } else if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }
        result += c;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solve("AsDf") == "aSdF");
    assert (solve("1234") == "4321");
    assert (solve("ab") == "AB");
    assert (solve("#a@C") == "#A@c");
    assert (solve("#AsdfW^45") == "#aSDFw^45");
    assert (solve("#6@2") == "2@6#");
    assert (solve("#$a^D") == "#$A^d");
    assert (solve("#ccc") == "#CCC");
}
