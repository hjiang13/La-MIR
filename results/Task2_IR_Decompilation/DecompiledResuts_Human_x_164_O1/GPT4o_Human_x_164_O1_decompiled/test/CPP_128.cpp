#include <vector>
#include <cstdlib>
#include <algorithm>

int prod_signs(std::vector<int> &vec) {
    int count = 0;
    int product = 1;
    size_t size = vec.size();

    if (size == 0) return 0;

    for (size_t i = 0; i < size; ++i) {
        int value = std::abs(vec[i]);
        count += (value != 0) ? 1 : 0;

        if (vec[i] < 0) {
            product *= -1;
        }
    }

    return (count == 0) ? 0 : product;
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
