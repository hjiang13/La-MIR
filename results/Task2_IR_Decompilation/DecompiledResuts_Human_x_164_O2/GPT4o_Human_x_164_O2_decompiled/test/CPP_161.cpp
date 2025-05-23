#include <string>
#include <cstring>

void solve(std::string &s, const std::string &t) {
    size_t s_len = s.size();
    size_t t_len = t.size();
    if (s_len == 0) {
        s = t;
        return;
    }
    
    for (size_t i = 0; i < s_len; ++i) {
        char c = s[i];
        if ('a' <= c && c <= 'z') {
            s[i] = c - 32;
        } else if ('A' <= c && c <= 'Z') {
            s[i] = c + 32;
        }
    }

    if (t_len > 15) {
        s.resize(t_len);
        std::memcpy(&s[0], t.data(), t_len);
    } else {
        s.resize(t_len + 1);
        std::memcpy(&s[0], t.data(), t_len);
        s[t_len] = '\0';
    }
    
    for (size_t i = 0; i < s_len; ++i) {
        char c = s[i];
        if (c == '\0') {
            break;
        }
    }

    s.resize(s_len);
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
