#include <string>

int is_bored(const std::string& str) {
    int count = 0;
    bool flag1 = true;
    bool flag2 = false;

    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            if (flag2) {
                flag2 = false;
                ++count;
            }
        } else if (str[i] == 'I') {
            if (flag1) {
                flag2 = true;
            }
        } else if (str[i] != ' ') {
            flag1 = false;
        }

        if (str[i] == '.' || str[i] == '?' || str[i] == '!') {
            flag1 = true;
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
