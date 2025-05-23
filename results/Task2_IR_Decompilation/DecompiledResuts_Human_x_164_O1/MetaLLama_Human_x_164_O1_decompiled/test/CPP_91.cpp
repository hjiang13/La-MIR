int is_bored(const char *str) {
    int count = 0;
    int len = strlen(str);
    int flag = 0;
    int n = 0;

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == ' ') {
            count += n;
            n = 0;
        }
        if (c == 'I' && flag) {
            n = 1;
        }
        if (c == '.' || c == '?' || c == '!') {
            flag = 1;
        } else {
            flag = 0;
        }
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
