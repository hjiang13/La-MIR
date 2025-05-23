#include <string>
#include <cstdlib>

bool simplify(const std::string& str1, const std::string& str2) {
    int num1_part1 = 0, num1_part2 = 0;
    int num2_part1 = 0, num2_part2 = 0;

    size_t pos = 0;
    while (pos < str1.size()) {
        if (str1[pos] == '/') {
            num1_part1 = std::atoi(str1.substr(0, pos).c_str());
            num1_part2 = std::atoi(str1.substr(pos + 1).c_str());
            break;
        }
        ++pos;
    }

    pos = 0;
    while (pos < str2.size()) {
        if (str2[pos] == '/') {
            num2_part1 = std::atoi(str2.substr(0, pos).c_str());
            num2_part2 = std::atoi(str2.substr(pos + 1).c_str());
            break;
        }
        ++pos;
    }

    int product1 = num1_part1 * num2_part1;
    int product2 = num1_part2 * num2_part2;

    return (product1 % product2) == 0;
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
