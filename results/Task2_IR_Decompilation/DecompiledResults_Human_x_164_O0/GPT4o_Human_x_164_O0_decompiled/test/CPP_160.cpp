#include <vector>
#include <string>
#include <cmath>

void do_algebra(std::vector<std::string>& strVec, std::vector<int>& intVec) {
    std::vector<int> tempVec;
    for (size_t i = 0; i < intVec.size(); ++i) {
        tempVec.push_back(intVec[i]);
    }

    for (size_t i = 0; i < strVec.size(); ++i) {
        if (strVec[i] == "**") {
            // some operation
        } else if (strVec[i] == "*") {
            // some operation
        } else if (strVec[i] == "//") {
            // some operation
        } else if (strVec[i] == "+") {
            // some operation
        } else if (strVec[i] == "-") {
            // some operation
        }
    }

    // Additional operations using tempVec
    for (size_t i = 0; i < tempVec.size(); ++i) {
        // Example operation: tempVec[i] = pow(tempVec[i], 2);
        tempVec[i] = static_cast<int>(pow(tempVec[i], 2));
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (do_algebra({"**", "*", "+"}, {2, 3, 4, 5}) == 37);
    assert (do_algebra({"+", "*", "-"}, {2, 3, 4, 5}) == 9);
    assert (do_algebra({"//", "*"}, {7, 3, 4}) == 8);
}
