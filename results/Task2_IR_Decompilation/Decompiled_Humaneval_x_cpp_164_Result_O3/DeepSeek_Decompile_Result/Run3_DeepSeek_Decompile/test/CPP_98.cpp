#include <string>

using namespace std;

int count_upper(const string& s) {
    string vowels = "AEIOU";
    int count = 0;
    
    for (char c : s) {
        for (char v : vowels) {
            if (c == v) {
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
