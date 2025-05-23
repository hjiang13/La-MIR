#include <string>
#include <cstdarg>
#include <cstdio>

void change_base(std::string& result, int base, int number) {
    std::string buffer;
    int remainder;
    if (base <= 0) return;

    do {
        remainder = number % base;
        number /= base;
        buffer.insert(buffer.begin(), '0' + remainder);
    } while (number != 0);

    result.append(buffer);
}

int main() {
    std::string result;
    change_base(result, 10, 255);
    printf("%s\n", result.c_str());
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (change_base(8, 3) == "22");
    assert (change_base(9, 3) == "100");
    assert (change_base(234, 2) == "11101010");
    assert (change_base(16, 2) == "10000");
    assert (change_base(8, 2) == "1000");
    assert (change_base(7, 2) == "111");
    for (int x=2;x<8;x++)
        assert (change_base(x, x + 1) == to_string(x));
}
