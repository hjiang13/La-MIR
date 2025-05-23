#include <string>

int count_upper(const std::string& input) {
    std::string vowels = "AEIOU";
    int count = 0;
    int index = 0;

    while (index * 2 < input.length()) {
        char current_char = input[index * 2];
        if (vowels.find(current_char) != std::string::npos) {
            count++;
        }
        index++;
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
