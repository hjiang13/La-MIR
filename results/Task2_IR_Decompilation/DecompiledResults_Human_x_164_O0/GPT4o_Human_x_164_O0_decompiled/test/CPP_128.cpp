#include <vector>
#include <cstdlib>

int abs(int x) {
    return (x < 0) ? -x : x;
}

int prod_signs(std::vector<int> &v) {
    int product = -32768;
    int count_positive = 0;
    int count_negative = 0;

    if (v.size() == 0) {
        return product;
    }

    for (size_t i = 0; i < v.size(); ++i) {
        int value = v[i];
        if (value == 0) {
            count_positive = 0;
        } else {
            if (value < 0) {
                count_negative++;
            }
            count_positive += abs(value);
        }
    }

    product = count_positive * count_negative;
    return product;
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
