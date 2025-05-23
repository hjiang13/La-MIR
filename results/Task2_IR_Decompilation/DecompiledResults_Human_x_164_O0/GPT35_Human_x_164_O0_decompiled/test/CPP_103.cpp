#include <string>
#include <stdexcept>

std::__cxx11::basic_string rounded_avg(int i, int j) {
    std::__cxx11::basic_string result;
    
    if (i > j) {
        result = "-1";
    } else {
        int avg = (i + j) / 2;
        result = std::to_string(avg % 2);
    }
    
    return result;
}

int main() {
    int a = 10;
    int b = 20;
    
    std::__cxx11::basic_string result = rounded_avg(a, b);
    
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
