#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float *data;
    float *begin;
    float *end;
} vector_data;

typedef struct {
    vector_data data;
} vector_base;

typedef struct {
    vector_base base;
} vector;

void _ZNSt6vectorIfSaIfEE17_M_realloc_insertIJfEEEvN9__gnu_cxx17__normal_iteratorIPfS1_EEDpOT_(vector *this, float *beginacin, float *value) {
    float *begin = this->base.data.begin;
    float *end = this->base.data.end;
    long size = (long)(end - begin);
    long new_size = size + 1;
    if (new_size > 2305843009213693951) {
        _ZSt17__throw_bad_allocv();
    }
    float *new_data = (float *)_Znwm(new_size * sizeof(float));
    if (begin != NULL) {
        _ZdlPv((void *)begin);
    }
    this->base.data.begin = new_data;
    this->base.data.end = new_data + new_size;
    new_data[size] = *value;
}

void _Z10derivativeSt6vectorIfSaIfEE(vector *result, vector *input) {
    float *begin = input->base.data.begin;
    float *end = input->base.data.end;
    long size = (long)(end - begin);
    result->base.data.begin = NULL;
    result->base.data.end = NULL;
    for (long i = 1; i < size; i++) {
        float value = begin[i] * (float)i;
        _ZNSt6vectorIfSaIfEE17_M_realloc_insertIJfEEEvN9__gnu_cxx17__normal_iteratorIPfS1_EEDpOT_(result, NULL, &value);
    }
}

void _ZdlPv(void *ptr) {
    free(ptr);
}

void *_Znwm(long size) {
    return malloc(size);
}

void _ZSt17__throw_bad_allocv() {
    printf("Bad alloc\n");
    exit(1);
}

void _ZSt20__throw_length_errorPKc(char *message) {
    printf("%s\n", message);
    exit(1);
}

int main() {
    vector input;
    float data[10] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f};
    input.base.data.begin = data;
    input.base.data.end = data + 10;
    vector result;
    _Z10derivativeSt6vectorIfSaIfEE(&result, &input);
    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(derivative({3, 1, 2, 4, 5}) , {1, 4, 12, 20}));
    assert (issame(derivative({1, 2, 3}) , {2, 6}));
    assert (issame(derivative({3, 2, 1}) , {2, 2}));
    assert (issame(derivative({3, 2, 1, 0, 4}) , {2, 2, 0, 16}));
    assert (issame(derivative({1}) , {}));
}
