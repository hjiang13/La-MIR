#include <stdint.h>

int will_it_fly(int* arr, int n, int threshold) {
    int sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] != arr[n - i - 1]) {
            break;
        }
        sum += arr[i];
    }
    return sum <= threshold;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (will_it_fly({3, 2, 3}, 9)==true);
    assert (will_it_fly({1, 2}, 5) == false);
    assert (will_it_fly({3}, 5) == true);
    assert (will_it_fly({3, 2, 3}, 1) == false);
    assert (will_it_fly({1, 2, 3}, 6) ==false);
    assert (will_it_fly({5}, 5) == true);
}
