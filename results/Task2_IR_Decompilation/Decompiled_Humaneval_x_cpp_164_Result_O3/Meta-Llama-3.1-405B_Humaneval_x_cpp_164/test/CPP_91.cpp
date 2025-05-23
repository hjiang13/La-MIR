#include <string.h>

int is_bored(const char* str) {
    int result = 0;
    int len = strlen(str);
    if (len == 0) return 0;

    int i = 0;
    if (len == 1) {
        if (str[0] == ' ') return 0;
        else return 1;
    }

    int j = 0;
    char prev = 1;
    while (j < len) {
        if (str[j] == ' ') {
            result += 1;
        }
        if (str[j] == 'I') {
            if (j + 1 < len && str[j + 1] == ' ') {
                if (prev) result += 1;
            }
        }
        if (str[j] == '.' || str[j] == '?' || str[j] == '!') {
            prev = 1;
        } else {
            prev = 0;
        }
        j += 1;
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
