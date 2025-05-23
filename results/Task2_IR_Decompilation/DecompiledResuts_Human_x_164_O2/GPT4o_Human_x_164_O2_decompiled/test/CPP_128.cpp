#include <vector>
#include <algorithm>
#include <cstdlib>

int prod_signs(std::vector<int>& vec) {
    int countNeg = 0;
    int countZero = 0;
    size_t size = vec.size();

    if (size == 0) return 0;

    for (size_t i = 0; i < size; ++i) {
        if (vec[i] == 0) {
            countZero++;
        } else if (vec[i] < 0) {
            countNeg++;
        }
    }

    if (countZero > 0) return 0;
    
    return (countNeg % 2 == 0) ? 1 : -1;
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
