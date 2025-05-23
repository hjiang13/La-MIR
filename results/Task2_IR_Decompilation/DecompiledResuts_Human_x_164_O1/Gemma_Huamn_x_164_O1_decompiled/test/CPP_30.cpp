#include <stdlib.h>
#include <string.h>

float* _ZSt20__throw_length_errorPKc(char* msg);
void* _Znwm(unsigned long long size);
void _ZdlPv(void* ptr);
void _ZSt17__throw_bad_allocv();
void _ZSt20__throw_length_errorPKc(char* msg);
void* memmove(void* dest, void* src, unsigned long long size);

typedef struct vector
{
  float* _M_start;
  float* _M_finish;
  float* _M_end_of_storage;
} vector;

void _Z12get_positiveSt6vectorIfSaIfEE(vector* __ret, vector* v1) {
  float* v2 = v1->_M_finish;
  float* v3 = v1->_M_start;
  memset(__ret, 0, sizeof(vector));
  if (v2 == v3) {
    return;
  }

  for (unsigned long long i = 0; i < (v2 - v3); i++) {
    float v4 = *(v3 + i);
    if (v4 > 0.0f) {
      if (__ret->_M_finish == __ret->_M_end_of_storage) {
        unsigned long long v5 = __ret->_M_finish - __ret->_M_start;
        unsigned long long v6 = v5 == 0 ? 1 : v5;
        unsigned long long v7 = v6 * 2;
        unsigned long long v8 = (v3 - __ret->_M_start) * sizeof(float);
        if (v7 > (unsigned long long)(2305843009213693951)) {
          _ZSt17__throw_bad_allocv();
        }
        float* v9 = (float*)malloc(v7 * sizeof(float));
        memcpy(v9, __ret->_M_start, v8);
        if (__ret->_M_start != NULL) {
          free(__ret->_M_start);
        }
        __ret->_M_start = v9;
        __ret->_M_finish = __ret->_M_start + v5;
        __ret->_M_end_of_storage = __ret->_M_start + v7;
      }
      *__ret->_M_finish = v4;
      __ret->_M_finish++;
    }
  }
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
    assert (issame(get_positive({-1, -2, 4, 5, 6}) , {4, 5, 6} ));
    assert (issame(get_positive({5, 3, -5, 2, 3, 3, 9, 0, 123, 1, -10}) , {5, 3, 2, 3, 3, 9, 123, 1}));
     assert (issame(get_positive({-1, -2}) , {} ));
     assert (issame(get_positive({}) , {}));
}
