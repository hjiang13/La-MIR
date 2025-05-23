#include <string>

bool strlen(std::string str) {
    int len = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            len++;
        } else if (str[i] == ')') {
            len--;
        }
        if (len < 0) {
            return false;
        }
    }
    return len == 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (strlen("") == 0);
    assert (strlen("x") == 1);
     assert (strlen("asdasnakj") == 9);
}
