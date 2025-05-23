#include <string>
#include <cstring>

void decimal_to_binary(std::string& s, int num) {
    if (num == 0) {
        s = "db0db";
    } else {
        int rem = num % 2;
        int quot = num / 2;
        
        char buffer[3];
        snprintf(buffer, 3, "%d", rem);
        s.append(buffer);
        
        decimal_to_binary(s, quot);
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (decimal_to_binary(0) == "db0db");
    assert (decimal_to_binary(32) == "db100000db");
    assert (decimal_to_binary(103) == "db1100111db");
    assert (decimal_to_binary(15) == "db1111db");

}
