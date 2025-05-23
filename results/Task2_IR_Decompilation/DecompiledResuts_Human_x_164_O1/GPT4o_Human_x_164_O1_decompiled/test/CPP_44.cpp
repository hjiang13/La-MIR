#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

void change_base(std::string &result, int base, int value) {
    std::string temp;
    if (base <= 0) return;

    int quotient = value / base;
    int remainder = value % base;

    vsnprintf(temp.data(), temp.size(), "%d", remainder);
    result.append(temp);

    result.resize(result.size() + 1);
    result[result.size() - 1] = '\0';
}

extern "C" {
    void __gxx_personality_v0();
}

int main() {
    std::string result;
    change_base(result, 10, 42);
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
