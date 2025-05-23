#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char c = str[i];
        int shifted = (c - 93) % 26;
        char encrypted = shifted + 97;
        str[i] = encrypted;
    }
}

int main() {
    char str[256];
    scanf("%s", str);
    encrypt(str);
    printf("%s\n", str);
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
