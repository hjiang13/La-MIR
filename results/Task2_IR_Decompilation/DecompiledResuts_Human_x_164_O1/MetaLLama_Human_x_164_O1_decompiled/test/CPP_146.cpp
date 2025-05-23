#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int specialFilter(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 10) {
            char str[16];
            sprintf(str, "%d", arr[i]);
            int len = strlen(str);
            if (len % 2 == 1) {
                if (str[len - 1] % 2 == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    // example usage
    int arr[] = {1, 12, 3, 14, 5, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = specialFilter(arr, size);
    printf("%d\n", result);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (specialFilter({5, -2, 1, -5}) == 0  );
    assert (specialFilter({15, -73, 14, -15}) == 1);
    assert (specialFilter({33, -2, -3, 45, 21, 109}) == 2);
    assert (specialFilter({43, -12, 93, 125, 121, 109}) == 4);
    assert (specialFilter({71, -2, -33, 75, 21, 19}) == 3);
    assert (specialFilter({1}) == 0              );
    assert (specialFilter({}) == 0                   );
}
