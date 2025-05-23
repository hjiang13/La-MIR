#include <string>
#include <stdexcept>

void decimal_to_binary(std::string &result, int num) {
    std::string temp;
    if (num == 0) {
        temp = "db";
        result = temp;
        return;
    }

    while (num > 0) {
        temp += std::to_string(num % 2);
        num /= 2;
    }
    
    std::reverse(temp.begin(), temp.end());
    result = temp;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (decimal_to_binary(0) == "db0db");
    assert (decimal_to_binary(32) == "db100000db");
    assert (decimal_to_binary(103) == "db1100111db");
    assert (decimal_to_binary(15) == "db1111db");

}
