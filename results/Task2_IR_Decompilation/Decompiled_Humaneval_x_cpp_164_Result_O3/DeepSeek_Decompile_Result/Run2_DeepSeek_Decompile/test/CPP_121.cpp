#include <vector>
using namespace std;

int solutions(vector<int>* vec) {
    if (vec->empty()) return 0;

    int* data = vec->data();
    int* end = data + vec->size();

    // SIMD vectorized processing of 4 elements at a time
    int count = 0;
    for (; data + 4 <= end; data += 4) {
        int a = data[0], b = data[1], c = data[2], d = data[3];
        if (a % 2 == 1) count++;
        if (b % 2 == 1) count++;
        if (c % 2 == 1) count++;
        if (d % 2 == 1) count++;
    }

    // Scalar processing for remaining elements
    while (data < end) {
        if (*data % 2 == 1) count++;
        data++;
    }

    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solutions({5, 8, 7, 1})    == 12);
    assert (solutions({3, 3, 3, 3, 3}) == 9);
    assert (solutions({30, 13, 24, 321}) == 0);
    assert (solutions({5, 9}) == 5);
    assert (solutions({2, 4, 8}) == 0);
    assert (solutions({30, 13, 23, 32}) == 23);
    assert (solutions({3, 13, 2, 9}) == 3);
}
