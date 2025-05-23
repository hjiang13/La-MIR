#include <string>

using namespace std;

int count_upper(const string& s) {
    const string vowels = "AEIOU";
    int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        for (size_t j = 0; j < vowels.size(); ++j) {
            if (c == vowels[j]) {
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
