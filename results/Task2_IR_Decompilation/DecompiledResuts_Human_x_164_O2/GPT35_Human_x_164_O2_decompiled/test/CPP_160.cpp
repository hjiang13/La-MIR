```cpp
#include <vector>
#include <string>
#include <cmath>

int do_algebra(std::vector<std::string>* vec1, std::vector<int>* vec2) {
    if (vec2->data() == nullptr) {
        return vec2->at(0);
    }

    for (size_t i = 0; i < vec2->size(); ++i) {
        if (vec2->at(i) == 0) {
            continue;
        }

        int val1 = vec1->at(i).compare("**");
        int val2 = vec1->at(i + 1).compare("*");
        int val3 = vec1->at(i + 2).compare("//");
        int val4 = vec1->at(i + 3).compare("+");
        int val5 = vec1->at(i + 4).compare("-");

        int result;
        if (val1 == 0) {
            result = pow(val2, val3);
        } else if (val4 == 0) {
            result = val2 + val3;
        } else if (val5 == 0) {
            result = val2 - val3;
        } else {
            result = val2 * val3;
        }

        vec2->at(i) = result;
    }

    return vec2->at(vec2->size() - 1);
}

int main() {
    std::vector<std::string> vec1 = {"**", "*", "//", "+", "-"};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};

    int result = do_algebra(&vec1, &vec2);

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (do_algebra({"**", "*", "+"}, {2, 3, 4, 5}) == 37);
    assert (do_algebra({"+", "*", "-"}, {2, 3, 4, 5}) == 9);
    assert (do_algebra({"//", "*"}, {7, 3, 4}) == 8);
}
