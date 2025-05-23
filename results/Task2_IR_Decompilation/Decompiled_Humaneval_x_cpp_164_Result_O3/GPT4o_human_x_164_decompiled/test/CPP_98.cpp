#include <string>

int count_upper(const std::string& str) {
    int count = 0;
    int len = str.length();

    if (len == 0) {
        return 0;
    }

    char upper_chars[5] = {'A', 'E', 'I', 'O', 'U'};
    
    for (int i = 0; i < len; ++i) {
        char current_char = str[i];
        for (int j = 0; j < 5; ++j) {
            if (current_char == upper_chars[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_upper("aBCdEf")  == 1);
    assert (count_upper("abcdefg") == 0);
    assert (count_upper("dBBE") == 0);
    assert (count_upper("B")  == 0);
    assert (count_upper("U")  == 1);
    assert (count_upper("") == 0);
    assert (count_upper("EEEE") == 2);
}
