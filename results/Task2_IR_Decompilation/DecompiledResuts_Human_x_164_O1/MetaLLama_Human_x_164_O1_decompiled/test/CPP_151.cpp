#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float* data;
    float* end;
    float* capacity;
} VectorImplData;

typedef struct {
    VectorImplData impl;
} VectorBase;

typedef struct {
    VectorBase base;
} Vector;

long double_the_difference(Vector* vec) {
    float* start = vec->base.impl.data;
    float* end = vec->base.impl.end;
    long size = (long)end - (long)start;

    if (size == 0) {
        return 0;
    }

    long len = size / 4;
    len = len > 1 ? len : 1;
    long result = 0;
    long i = 0;

    do {
        float val = start[i];
        float rounded = roundf(val);
        float diff = val - rounded;
        if (diff < 1e-4 && val > 0) {
            int int_val = (int)rounded;
            if (int_val % 2 == 1) {
                result += int_val * int_val;
            }
        }
        i++;
    } while (i < len);

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (double_the_difference({}) == 0);
    assert (double_the_difference({5, 4}) == 25);
    assert (double_the_difference({0.1, 0.2, 0.3}) == 0 );
    assert (double_the_difference({-10, -20, -30}) == 0 );
    assert (double_the_difference({-1, -2, 8}) == 0);
    assert (double_the_difference({0.2, 3, 5}) == 34);
    
    
    long long odd_sum=0;
    vector<float> lst={};

    for (int i=-99;i<100;i+=2)
    {
        lst.push_back(i+0.0);
        if (i>0 and i%2==1) odd_sum+=i*i;
    }
  
    assert (double_the_difference(lst) == odd_sum );
}
