#include <string.h>
#include <stdlib.h>

void intersection(char** result, int* v1, int size1, int* v2, int size2) {
    int min_size = (size1 < size2) ? size1 : size2;
    int diff = abs(v2[1] - v1[1]);
    if (diff < 2) {
        *result = strdup("NO");
    } else if (diff < 4) {
        int i = 2;
        while (1) {
            int square = i * i;
            if (square > diff) {
                *result = strdup("NO");
                break;
            }
            if (diff % i == 0) {
                *result = strdup("YES");
                break;
            }
            i++;
        }
    } else {
        *result = strdup("YES");
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (intersection({1, 2}, {2, 3}) == "NO");
    assert (intersection({-1, 1}, {0, 4}) == "NO");
    assert (intersection({-3, -1}, {-5, 5}) == "YES");
    assert (intersection({-2, 2}, {-4, 0}) == "YES");
    assert (intersection({-11, 2}, {-1, -1}) == "NO");
    assert (intersection({1, 2}, {3, 5}) == "NO");
    assert (intersection({1, 2}, {1, 2}) == "NO");
    assert (intersection({-2, -2}, {-3, -2}) == "NO");
}
