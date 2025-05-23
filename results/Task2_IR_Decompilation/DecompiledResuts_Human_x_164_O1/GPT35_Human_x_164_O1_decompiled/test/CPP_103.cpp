#include <string>
#include <cstdio>
#include <cstdarg>

void rounded_avg(std::string& s, int a, int b) {
    if (a > b) {
        s = std::to_string((a + b) / 2);
    } else {
        s = std::to_string((a + b) / 2);
    }
}

int main() {
    std::string result;
    rounded_avg(result, 10, 20);
    printf("%s\n", result.c_str());
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (rounded_avg(1, 5) == "11");
    assert (rounded_avg(7, 13) == "1010");
    assert (rounded_avg(964,977) == "1111001010");
    assert (rounded_avg(996,997) == "1111100100");
    assert (rounded_avg(560,851) == "1011000001");  
    assert (rounded_avg(185,546) == "101101101");
    assert (rounded_avg(362,496) == "110101101");
    assert (rounded_avg(350,902) == "1001110010");
    assert (rounded_avg(197,233) == "11010111");
    assert (rounded_avg(7, 5) == "-1");
    assert (rounded_avg(5, 1) == "-1");
    assert (rounded_avg(5, 5) == "101");
}
