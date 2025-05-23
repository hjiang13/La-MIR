#include <vector>
#include <algorithm>

int prod_signs(std::vector<int> v) {
    int result = -32768;
    for (size_t i = 0; i < v.size(); i++) {
        int num = std::abs(v[i]);
        result = result * ((v[i] < 0) ? -1 : 1) + num;
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
