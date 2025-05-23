#include <string>
#include <iostream>

int digitSum(std::string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            sum += c - 'a' + 1;
        }
    }
    return sum;
}

int main() {
    std::string input = "example_string";
    int result = digitSum(input);
    std::cout << "Digit sum of input string is: " << result << std::endl;
    return 0;
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
