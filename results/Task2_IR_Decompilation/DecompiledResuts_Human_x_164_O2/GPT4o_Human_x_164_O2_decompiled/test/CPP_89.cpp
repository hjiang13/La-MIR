#include <string>
#include <cstring>

void encrypt(std::string &output, const std::string &input) {
    size_t len = input.length();
    if (len == 0) {
        output = "";
        return;
    }

    output.resize(len);
    for (size_t i = 0; i < len; ++i) {
        output[i] = static_cast<char>((static_cast<unsigned char>(input[i]) - 93) % 26 + 97);
    }
    output[len] = '\0';
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
