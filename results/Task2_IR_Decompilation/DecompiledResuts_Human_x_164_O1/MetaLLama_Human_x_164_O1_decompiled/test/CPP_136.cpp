#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct VectorImplData {
    int* start;
    int* end;
    int* capacity;
};

struct VectorBase {
    struct VectorImplData impl;
};

struct Vector {
    struct VectorBase base;
};

void largestSmallestIntegers(struct Vector* result, struct Vector* input) {
    int* start = input->base.impl.start;
    int* end = input->base.impl.end;
    int size = end - start;

    if (size == 0) {
        result->base.impl.start = NULL;
        result->base.impl.end = NULL;
        result->base.impl.capacity = NULL;
        return;
    }

    int capacity = (size + 1) / 2;
    int* data = (int*)malloc(sizeof(int) * capacity * 2);
    int min = 0;
    int max = 0;

    for (int i = 0; i < size; i++) {
        int value = start[i];
        if (value < 0) {
            if (min == 0 || value < min) {
                min = value;
            }
        } else {
            if (max == 0 || value > max) {
                max = value;
            }
        }
    }

    result->base.impl.start = data;
    result->base.impl.end = data + capacity;
    result->base.impl.capacity = data + capacity;
    data[0] = min;
    data[1] = max;
}

int main() {
    struct Vector input;
    struct Vector result;
    // Initialize input vector
    input.base.impl.start = (int*)malloc(sizeof(int) * 10);
    input.base.impl.end = input.base.impl.start + 10;
    input.base.impl.capacity = input.base.impl.start + 10;

    // Assign some values to input vector
    for (int i = 0; i < 10; i++) {
        input.base.impl.start[i] = i;
    }

    largestSmallestIntegers(&result, &input);

    // Print result
    printf("Min: %d\n", result.base.impl.start[0]);
    printf("Max: %d\n", result.base.impl.start[1]);

    return 0;
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
