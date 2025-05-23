#include <string>

int strlen(const std::string& str) {
    return static_cast<int>(str.size());
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (strlen("") == 0);
    assert (strlen("x") == 1);
     assert (strlen("asdasnakj") == 9);
}
