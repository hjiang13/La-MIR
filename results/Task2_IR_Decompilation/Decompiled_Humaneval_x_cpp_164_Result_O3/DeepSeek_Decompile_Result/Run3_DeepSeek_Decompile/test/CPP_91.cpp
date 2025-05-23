#include <string>

int is_bored(const std::string &s) {
    int result = 0;
    size_t length = s.length();
    if (length == 0) return 0;

    const char* data = s.data();
    bool in_pair = (length & 1) != 0;

    if (in_pair) {
        size_t i = 0;
        int count = 0;
        while (i < length) {
            if (s[i] == ' ') {
                result += count;
            }
            ++i;
        }
    } else {
        size_t i = 0;
        while (i < length) {
            if (s[i] == 's' && i + 1 < length && s[i+1] == ' ') {
                if (i + 2 < length && s[i+2] == 'S') {
                    ++result;
                }
            }
            ++i;
        }
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_bored("Hello world") == 0);
    assert (is_bored("Is the sky blue?") == 0);
    assert (is_bored("I love It !") == 1);
    assert (is_bored("bIt") == 0);
    assert (is_bored("I feel good today. I will be productive. will kill It") == 2);
    assert (is_bored("You and I are going for a walk") == 0);
}
