#include <iostream>
#include <string>

using namespace std;

int is_bored(string str) {
    int len = str.length();
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            count++;
        } else if (str[i] == ')') {
            count--;
        }
        if (count < 0) {
            return 0;
        }
    }
    if (count != 0) {
        return 0;
    }
    return 1;
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
