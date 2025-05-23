#include <string>

using namespace std;

int is_bored(const string& s) {
    int len = s.length();
    if (len == 0) return 0;

    const char* data = s.data();
    int i = 0;
    int state = 0;
    int count = 0;
    int cond1 = 0;
    int cond2 = 0;

    while (true) {
        if (i >= len) break;

        char c = data[i];
        if (c == ' ') {
            count += cond2;
            cond2 = 0;
        } else if (c == 's' || c == 'S' || c == 't' || c == 'T') {
            cond1 = 1;
        }

        if (c == ' ') {
            cond1 = 0;
        } else if (c == ' ') {
            cond2 = 1;
        }

        if (c == ' ') {
            if (state & 1) {
                count++;
            }
            state = 0;
        } else if (c == ' ') {
            state |= 1;
        }

        i++;
    }

    return count;
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
