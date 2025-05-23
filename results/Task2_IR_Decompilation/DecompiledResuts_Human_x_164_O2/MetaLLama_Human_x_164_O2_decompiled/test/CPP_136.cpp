#include <stdlib.h>
#include <string.h>

void largest_smallest_integers(int** result, int* arr, int len) {
    int max = 0;
    int min = 0;
    if (len == 0) {
        *result = (int*)malloc(2 * sizeof(int));
        (*result)[0] = min;
        (*result)[1] = max;
        return;
    }

    max = arr[0];
    min = arr[0];

    for (int i = 1; i < len; i++) {
        if (arr[i] < 0) {
            if (min == 0 || arr[i] > min) {
                min = arr[i];
            }
        } else if (arr[i] != 0) {
            if (max == 0 || arr[i] < max) {
                max = arr[i];
            }
        }
    }

    *result = (int*)malloc(2 * sizeof(int));
    (*result)[0] = min;
    (*result)[1] = max;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(largest_smallest_integers({2, 4, 1, 3, 5, 7}) , {0, 1}));
    assert (issame(largest_smallest_integers({2, 4, 1, 3, 5, 7, 0}) , {0, 1}));
    assert (issame(largest_smallest_integers({1, 3, 2, 4, 5, 6, -2}) , {-2, 1}));
    assert (issame(largest_smallest_integers({4, 5, 3, 6, 2, 7, -7}) , {-7, 2}));
    assert (issame(largest_smallest_integers({7, 3, 8, 4, 9, 2, 5, -9}) , {-9, 2}));
    assert (issame(largest_smallest_integers({}) , {0, 0}));
    assert (issame(largest_smallest_integers({0}) , {0, 0}));
    assert (issame(largest_smallest_integers({-1, -3, -5, -6}) , {-1, 0}));
    assert (issame(largest_smallest_integers({-1, -3, -5, -6, 0}) , {-1, 0}));
    assert (issame(largest_smallest_integers({-6, -4, -4, -3, 1}) , {-3, 1}));
    assert (issame(largest_smallest_integers({-6, -4, -4, -3, -100, 1}) , {-3, 1}));

}
