#include <vector>

int prod_signs(const std::vector<int>& v) {
    if (v.empty()) {
        return -32768;
    }
    int sign = 1;
    for (int num : v) {
        if (num != 0) {
            if (num < 0) {
                sign *= -1;
            }
        }
    }
    return sign;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (prod_signs({1, 2, 2, -4}) == -9);
    assert (prod_signs({0, 1}) == 0);
    assert (prod_signs({1, 1, 1, 2, 3, -1, 1}) == -10);
    assert (prod_signs({}) == -32768);
    assert (prod_signs({2, 4,1, 2, -1, -1, 9}) == 20);
    assert (prod_signs({-1, 1, -1, 1}) == 4);
    assert (prod_signs({-1, 1, 1, 1}) == -4);
    assert (prod_signs({-1, 1, 1, 0}) == 0);
}
