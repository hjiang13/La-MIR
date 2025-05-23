#include <iostream>
#include <string>
#include <cstdarg>

void rounded_avg(std::string& result, int a, int b) {
    if (a > b) {
        result = std::string(2, '\0');
        *((int16_t*)(result.data() + 2)) = 12589; 
        *((int64_t*)(result.data() + 8)) = 2; 
        result[10] = 0; 
    } else {
        std::string temp1, temp2;
        int sum = a + b;
        if (sum > 1) {
            int avg = sum / 2;
            char buffer[16];
            int length = snprintf(buffer, sizeof(buffer), "%d", avg);
            temp2 = std::string(buffer, length);
            result.append(temp2);
        }
    }
    result += '\0';
}

int main() {
    std::string output;
    rounded_avg(output, 5, 3);
    std::cout << output << std::endl;
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
