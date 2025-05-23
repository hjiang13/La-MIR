#include <string>
#include <cstring>
#include <cstdlib>

void encrypt(std::string &output, const std::string &input) {
    size_t inputLength = input.length();
    output.resize(inputLength);
    if (inputLength == 0) {
        return;
    }

    for (size_t i = 0; i < inputLength; ++i) {
        output[i] = (input[i] - 93 + 26) % 26 + 'a';
    }
    output[inputLength] = '\0';
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
