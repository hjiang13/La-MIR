#include <vector>
#include <cstdlib> // for std::abs

using namespace std;

int prod_signs(const vector<int>& v) {
    if (v.empty()) {
        return -32768; // Assuming this is the intended return value for empty vectors
    }

    int result = 1;
    int accumulator = 0;

    size_t size = v.size();
    size_t half_size = (size + 1) / 2;

    for (size_t i = 0; i < half_size; ++i) {
        int a = abs(v[i * 2]);
        int b = (i * 2 + 1 < size) ? abs(v[i * 2 + 1]) : 0;

        int sign_a = (a == 0) ? 0 : (v[i * 2] > 0 ? 1 : -1);
        int sign_b = (b == 0) ? 0 : (v[i * 2 + 1] > 0 ? 1 : -1);

        accumulator += sign_a;
        accumulator += sign_b;

        result *= (sign_a * sign_b);
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
