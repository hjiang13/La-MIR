#include <iostream>
#include <string>

using namespace std;

int digitSum(string digits) {
    int sum = 0;
    for (int i = 0; i < digits.length(); i++) {
        if (digits[i] >= '0' && digits[i] <= '9') {
            sum += digits[i] - '0';
        }
    }
    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (digitSum("") == 0);
    assert (digitSum("abAB") == 131);
    assert (digitSum("abcCd") == 67);
    assert (digitSum("helloE") == 69);
    assert (digitSum("woArBld") == 131);
    assert (digitSum("aAaaaXa") == 153);
    assert (digitSum(" How are yOu?") == 151);
    assert (digitSum("You arE Very Smart") == 327);
}
