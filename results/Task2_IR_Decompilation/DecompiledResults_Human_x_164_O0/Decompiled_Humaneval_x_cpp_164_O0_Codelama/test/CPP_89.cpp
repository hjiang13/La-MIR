#include <string>

using namespace std;

basic_string<char> _Z7encryptNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(basic_string<char>* str) {
    basic_string<char> result;
    for (int i = 0; i < str->length(); i++) {
        char c = str->at(i);
        c = (c + 4) % 26;
        result.append(c);
    }
    return result;
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
