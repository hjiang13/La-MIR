#include <string>

std::string encrypt(std::string input) {
    std::string output;
    for (size_t i = 0; i < input.length(); ++i) {
        char ch = input[i];
        char encrypted_char = (ch - 'a' + 4) % 26 + 'a'; // Simple shift encryption
        output += encrypted_char;
    }
    return output;
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
