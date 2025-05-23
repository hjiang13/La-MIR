#include <vector>
#include <cstdlib>

int prod_signs(const std::vector<int>& vec) {
    if (vec.size() == 0) {
        return -32768;
    }

    int sum_abs = 0;
    int sign_product = 1;

    for (size_t i = 0; i < vec.size(); ++i) {
        sum_abs += std::abs(vec[i]);
        if (vec[i] == 0) {
            sign_product = 0;
        } else if (vec[i] < 0) {
            sign_product = -sign_product;
        }
    }

    return sum_abs * sign_product;
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
