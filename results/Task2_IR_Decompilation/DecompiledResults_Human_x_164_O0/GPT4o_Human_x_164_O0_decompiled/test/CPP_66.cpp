#include <string>

int digitSum(const std::string& str) {
    int sum = 0;
    size_t index = 0;

    while (index < str.length()) {
        char ch = str[index];
        if (ch >= 'A' && ch <= 'Z') {
            sum += static_cast<int>(ch);
        }
        if (ch <= 'z' && ch >= 'a') {
            sum += static_cast<int>(ch);
        }
        index++;
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
