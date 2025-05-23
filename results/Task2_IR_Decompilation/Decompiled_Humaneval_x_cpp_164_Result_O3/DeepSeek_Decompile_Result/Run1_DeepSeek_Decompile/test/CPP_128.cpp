#include <vector>
#include <cstdlib> // for abs function

int prod_signs(std::vector<int>& vec) {
    if (vec.empty()) {
        return -32768;
    }

    int result = 1;
    size_t n = vec.size();
    size_t half = (n / 2);

    for (size_t i = 0; i < half; ++i) {
        int a = abs(vec[i]);
        int b = abs(vec[i + (i + 1) < n]);
        int sign_a = (a == 0) ? 1 : (vec[i] / a);
        int sign_b = (b == 0) ? 1 : (vec[i + (i + 1) < n] / b);
        result *= sign_a * sign_b;
    }

    if (n % 2 != 0) {
        int last = abs(vec.back());
        int sign_last = (last == 0) ? 1 : (vec.back() / last);
        result *= sign_last;
    }

    return result;
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
