#include <stdio.h>
#include <stdbool.h>

bool will_it_fly(int* arr, int size, int threshold) {
    int start = 0;
    int end = size - 1;
    int sum = 0;
    while (start <= end) {
        if (arr[start] == arr[end]) {
            sum += arr[start];
            start++;
            end--;
        } else {
            break;
        }
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
