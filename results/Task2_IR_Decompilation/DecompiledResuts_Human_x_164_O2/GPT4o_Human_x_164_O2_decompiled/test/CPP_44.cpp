#include <cstring>
#include <cstdarg>
#include <string>

void change_base(std::string &str, int base, int num) {
    std::string temp;
    std::string format = "%d";
    
    if (base > 0) {
        int quotient = num / base;
        int remainder = num % base;

        char buffer[32];
        snprintf(buffer, sizeof(buffer), format.c_str(), remainder);
        temp += buffer;

        while (quotient > 0) {
            remainder = quotient % base;
            quotient = quotient / base;
            snprintf(buffer, sizeof(buffer), format.c_str(), remainder);
            temp += buffer;
        }

        str += temp;
    }
}

int main() {
    std::string result;
    change_base(result, 10, 123);
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
