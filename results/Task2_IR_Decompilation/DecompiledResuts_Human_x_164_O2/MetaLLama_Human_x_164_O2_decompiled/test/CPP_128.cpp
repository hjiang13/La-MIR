#include <stdint.h>

int prod_signs(int* data, int size) {
    int result = 1;
    int sum = 0;
    if (size == 0) {
        return -32768;
    }
    int i;
    for (i = 0; i < size - 1; i += 2) {
        int a = data[i];
        int b = data[i + 1];
        sum += abs(a);
        sum += abs(b);
        if (a == 0) {
            result = 0;
        } else if (a < 0) {
            result = -result;
        }
        if (b == 0) {
            result = 0;
        } else if (b < 0) {
            result = -result;
        }
    }
    if (size & 1) {
        int a = data[i];
        sum += abs(a);
        if (a == 0) {
            result = 0;
        } else if (a < 0) {
            result = -result;
        }
    }
    return result * sum;
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
