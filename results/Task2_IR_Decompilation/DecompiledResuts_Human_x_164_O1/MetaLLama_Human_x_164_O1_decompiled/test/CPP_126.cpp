#include <stdbool.h>

bool is_sorted(int* arr, int len) {
    if (len <= 1) return true;

    for (int i = 1; i < len; i++) {
        if (arr[i] < arr[i - 1]) return false;

        if (i > 1 && arr[i] == arr[i - 1] && arr[i] == arr[i - 2]) return false;
    }

    return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_sorted({5}) == true);
    assert (is_sorted({1, 2, 3, 4, 5}) == true);
    assert (is_sorted({1, 3, 2, 4, 5}) == false);
    assert (is_sorted({1, 2, 3, 4, 5, 6}) == true);
    assert (is_sorted({1, 2, 3, 4, 5, 6, 7}) == true);
    assert (is_sorted({1, 3, 2, 4, 5, 6, 7}) == false);
    assert (is_sorted({}) == true);
    assert (is_sorted({1}) == true);
    assert (is_sorted({3, 2, 1}) == false);
    assert (is_sorted({1, 2, 2, 2, 3, 4}) == false);
    assert (is_sorted({1, 2, 3, 3, 3, 4}) == false);
    assert (is_sorted({1, 2, 2, 3, 3, 4}) == true);
    assert (is_sorted({1, 2, 3, 4}) == true);
}
