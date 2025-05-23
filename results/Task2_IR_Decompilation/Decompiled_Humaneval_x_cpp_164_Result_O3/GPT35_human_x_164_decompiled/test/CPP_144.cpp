#include <string>
#include <cstdlib>

bool simplify(std::string& str1, std::string& str2) {
    if (str1.size() == 0) {
        return false;
    }

    int pos = 0;
    while (str1[pos] == '/') {
        pos++;
    }

    if (pos == str1.size()) {
        return false;
    }

    str2 = str1.substr(pos);

    return true;
}

int main() {
    std::string input1 = "/basic_string::substr";
    std::string input2;

    if (simplify(input1, input2)) {
        std::cout << "Result: " << input2 << std::endl;
    } else {
        std::cout << "Failed to simplify string" << std::endl;
    }

    return 0;
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
