#include <string>

int digitSum(const std::string& str) {
    int sum = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            sum += c;
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
