#include <string>

int strlen(const std::string& s) {
    return static_cast<int>(s.length());
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (strlen("") == 0);
    assert (strlen("x") == 1);
     assert (strlen("asdasnakj") == 9);
}
