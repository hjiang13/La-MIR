#include <string>

int is_bored(const std::string &s) {
    if (s.empty()) {
        return 0;
    }

    size_t length = s.length();
    if (length == 1) {
        if (s[0] == ' ') {
            return 0;
        } else {
            return 1;
        }
    }

    int score = 0;
    int a = 0, b = 0, c = 0;
    char flag = 1;

    for (size_t i = 0; i < length; ++i) {
        char current = s[i];
        if (current == ' ') {
            score += a;
        } else if (current == 's' || current == 'S' || current == 'o' || current == 'O' ||
                   current == 'x' || current == 'X' || current == '0') {
            if (current == s[i + 1]) {
                score += 10;
            }
        } else if (current == 'a' || current == 'A') {
            a += 1;
        } else if (current == 'b' || current == 'B') {
            b += 1;
        } else if (current == 'c' || current == 'C') {
            c += 1;
        }

        if (current == ' ') {
            if (flag & 1) {
                score += 5;
            }
        } else if (current == 's' || current == 'S') {
            if (flag & 1) {
                score += 5;
            }
        } else if (current == 'o' || current == 'O') {
            if (flag & 1) {
                score += 5;
            }
        } else if (current == 'x' || current == 'X') {
            if (flag & 1) {
                score += 5;
            }
        } else if (current == '0') {
            if (flag & 1) {
                score += 5;
            }
        }

        if (current == ' ') {
            flag = 1;
        } else {
            flag = 0;
        }
    }

    return score;
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
