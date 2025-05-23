#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

int skjkasdkd(std::vector<int>& vec) {
    std::string str1;
    std::string str2;
    int size = vec.size();
    
    if (size == 0) {
        return 0;
    }

    int result = 0;

    for (size_t i = 0; i < size; ++i) {
        int value = vec[i];
        if (value > 0) {
            if (value < 4) {
                result = value;
            } else {
                int divisor = 2;
                while (divisor * divisor <= value) {
                    if (value % divisor == 0) {
                        result = divisor;
                        break;
                    }
                    ++divisor;
                }
                if (result == 0) {
                    result = value;
                }
            }
        }
    }

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", result);
    str1 = buffer;

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (skjkasdkd({0,3,2,1,3,5,7,4,5,5,5,2,181,32,4,32,3,2,32,324,4,3}) == 10);
    assert (skjkasdkd({1,0,1,8,2,4597,2,1,3,40,1,2,1,2,4,2,5,1}) == 25);
    assert (skjkasdkd({1,3,1,32,5107,34,83278,109,163,23,2323,32,30,1,9,3}) == 13);
    assert (skjkasdkd({0,724,32,71,99,32,6,0,5,91,83,0,5,6}) == 11);
    assert (skjkasdkd({0,81,12,3,1,21}) == 3);
    assert (skjkasdkd({0,8,1,2,1,7}) == 7);
    assert (skjkasdkd({8191}) == 19);
    assert (skjkasdkd({8191, 123456, 127, 7}) == 19);
    assert (skjkasdkd({127, 97, 8192}) == 10);
}
