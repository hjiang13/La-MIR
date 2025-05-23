#include <iostream>
#include <string>

int count_upper(std::__cxx11::basic_string<char> str) {
    const char vowels[] = "AEIOU";
    int count = 0;

    for (char c : str) {
        for (char vowel : vowels) {
            if (c == vowel) {
                count++;
                break;
            }
        }
    }

    return count;
}

int main() {
    std::__cxx11::basic_string<char> str = "Hello World";
    int result = count_upper(str);
    
    std::cout << "Number of uppercase vowels: " << result << std::endl;

    return 0;
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
