```c++
#include <string>
#include <cstring>

void encrypt(std::string& res, const std::string& input) {
    res = "";
    if (input.empty()) {
        return;
    }
    
    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        int diff = c - 93;
        int offset = diff % 26;
        char encrypted = static_cast<char>(offset + 97);
        res += encrypted;
    }
}

int main() {
    std::string input = "hello world";
    std::string encrypted;
    
    encrypt(encrypted, input);
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (encrypt("hi") == "lm");
    assert (encrypt("asdfghjkl") == "ewhjklnop");
    assert (encrypt("gf") == "kj");
    assert (encrypt("et") == "ix");
    assert (encrypt("faewfawefaewg")=="jeiajeaijeiak");
    assert (encrypt("hellomyfriend")=="lippsqcjvmirh");
    assert (encrypt("dxzdlmnilfuhmilufhlihufnmlimnufhlimnufhfucufh")=="hbdhpqrmpjylqmpyjlpmlyjrqpmqryjlpmqryjljygyjl");
    assert (encrypt("a")=="e");
}
