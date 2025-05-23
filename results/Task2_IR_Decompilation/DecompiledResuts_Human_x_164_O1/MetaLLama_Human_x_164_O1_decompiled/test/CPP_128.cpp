#include <stdio.h>
#include <stdlib.h>

int prod_signs(int* arr, int len) {
    if (len == 0)
        return 0;

    int signs = 0;
    int sum = 0;
    int x;
    for (int i = 0; i < len; i++) {
        x = abs(arr[i]);
        sum += x;
        if (arr[i] < 0)
            signs = -signs;
        else if (arr[i] != 0)
            signs = 1;
    }
    return signs * sum;
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
