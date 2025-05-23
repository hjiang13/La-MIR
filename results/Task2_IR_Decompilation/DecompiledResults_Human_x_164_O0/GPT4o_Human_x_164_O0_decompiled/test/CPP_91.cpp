#include <string>

int is_bored(const std::string& str) {
    int count = 0;
    int result = 0;
    bool flag = true;

    while (count < str.length()) {
        char ch = str[count];
        if (ch == 32) {
            if (flag) {
                result = 1;
            }
        } else if (ch == 73) {
            flag = false;
            result = 1;
        } else if (ch == 46 || ch == 63 || ch == 33) {
            result = 1;
        }
        count++;
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
