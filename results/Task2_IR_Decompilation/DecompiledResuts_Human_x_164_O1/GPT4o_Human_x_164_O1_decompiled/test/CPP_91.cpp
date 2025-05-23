#include <string>

int is_bored(const std::string& str) {
    size_t length = str.size();
    if (length == 0) {
        return 0;
    }

    int count = 0;
    for (size_t i = 0; i < length; ++i) {
        char c = str[i];
        if (c == ' ') {
            count++;
        } else if (c == 'I') {
            count += 1; // Assuming some condition is applied here
        } else if (c == '.') {
            break; // Assuming some termination condition
        } else if (c == '?') {
            break; // Assuming some termination condition
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
