#include <stdint.h>

int can_arrange(int* arr, int n) {
    int i, j, k, l, m, x, y, z;
    int* p;
    int res = -1;

    if (n == 0) {
        return -1;
    }

    i = n >> 2;
    i = (i == 0) ? 1 : i;
    j = i - 1;
    k = i & 3;
    p = arr;

    if (j < 3) {
        while (k != 0) {
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            k--;
        }
    } else {
        i &= -4;
        while (i != 0) {
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            i -= 4;
        }
        while (k != 0) {
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            k--;
        }
    }

    return res;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (can_arrange({1,2,4,3,5})==3);
    assert (can_arrange({1,2,4,5})==-1);
    assert (can_arrange({1,4,2,5,6,7,8,9,10})==2);
    assert (can_arrange({4,8,5,7,3})==4);
    assert (can_arrange({})==-1);
}
