#include <string>
#include <cstdlib>
#include <stdexcept>

bool simplify(std::string s1, std::string s2) {
    int pos1 = 0, pos2 = 0;
    while (true) {
        if (pos1 >= s1.size()) {
            if (pos2 >= s2.size()) {
                return true;
            }
            return false;
        }
        if (pos2 >= s2.size()) {
            return false;
        }
        if (s1[pos1] == '/') {
            pos1++;
            continue;
        }
        if (s2[pos2] == '/') {
            pos2++;
            continue;
        }
        if (s1[pos1] == s2[pos2]) {
            pos1++;
            pos2++;
            continue;
        }
        return false;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (simplify("1/5", "5/1") == true);
    assert (simplify("1/6", "2/1") == false);
    assert (simplify("5/1", "3/1") == true);
    assert (simplify("7/10", "10/2") == false);
    assert (simplify("2/10", "50/10") == true);
    assert (simplify("7/2", "4/2") == true);
    assert (simplify("11/6", "6/1") == true);
    assert (simplify("2/3", "5/2") == false);
    assert (simplify("5/2", "3/5") == false);
    assert (simplify("2/4", "8/4") == true);
    assert (simplify("2/4", "4/2") == true);
    assert (simplify("1/5", "5/1") == true);
    assert (simplify("1/5", "1/5") == false);
}
