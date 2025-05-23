#include <string>

using namespace std;

int count_upper(const string& s) {
    int count = 0;
    const char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    for (size_t i = 0; i < s.size(); ++i) {
        for (const auto c : vowels) {
            if (s[i] == c) {
                ++count;
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
