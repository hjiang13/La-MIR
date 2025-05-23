#include <string>

int strlen(std::__cxx11::basic_string<char> *str) {
    return str->length();
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (strlen("") == 0);
    assert (strlen("x") == 1);
     assert (strlen("asdasnakj") == 9);
}
