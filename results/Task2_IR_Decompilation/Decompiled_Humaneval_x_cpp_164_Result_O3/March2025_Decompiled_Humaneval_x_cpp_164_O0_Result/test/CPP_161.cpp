#include <string>
#include <algorithm>
#include <stdexcept>

void solve(std::string& result, const std::string& input) {
    std::string temp;
    std::allocator<char> alloc;
    try {
        temp = std::string("", alloc);
    } catch (...) {
        throw;
    }

    int count = 0;
    for (int i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        } else if (c >= 'a' && c <= 'z') {
            c -= 32;
        } else {
            ++count;
        }
        temp += c;
    }

    if (count == input.length()) {
        result = std::string(input.rbegin(), input.rend(), alloc);
    } else {
        result = std::move(temp);
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
