#include <string>
#include <cstdlib>
#include <stdexcept>

bool simplify(std::string str1, std::string str2) {
    size_t pos1 = str1.size();
    size_t pos2 = str2.size();
    
    if (pos1 == 0) {
        return pos2 == 0;
    }

    size_t i = 0;
    while (i < pos1) {
        if (str1[i] == '/') {
            i++;
            continue;
        }
        size_t j = 0;
        while (j < pos2 && j < pos1) {
            if (str2[j] == '/') {
                j++;
                continue;
            }
            if (str1[i] == str2[j]) {
                break;
            }
            j++;
        }
        if (j == pos2) {
            return false;
        }
        i++;
    }
    return true;
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
