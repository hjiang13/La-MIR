#include <string>
#include <cstdarg>
#include <cstring>

void rounded_avg(std::string &result, int a, int b) {
    if (a > b) {
        result = std::string(2, '\0');
        *(reinterpret_cast<uint64_t*>(&result) + 1) = 2;
        *(reinterpret_cast<uint16_t*>(&result) + 2) = 12589;
        result[2] = '\0';
    } else {
        std::string temp1;
        std::string temp2;
        int sum = a + b;

        if (sum > 1) {
            int avg = sum / 2;
            char buffer[16];
            int length = snprintf(buffer, sizeof(buffer), "%d", avg);
            temp2.append(buffer, length);
            result.append(temp2);
        } else {
            result.clear();
        }
    }
}

int main() {
    std::string result;
    rounded_avg(result, 5, 3);
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
