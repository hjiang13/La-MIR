#include <stdint.h>

typedef struct {
  int *begin;
  int *end;
  int *capacity;
} std_vector;

void sum_product(std_vector *result, const std_vector *v) {
  int *first = v->end;
  int *last = v->begin;
  int a = 0;
  int b = 1;

  if (first != last) {
    int64_t len = first - last;
    if (len >= 8) {
      for (int64_t i = 0; i < len / 8; ++i) {
        int32_t v0 = last[0];
        int32_t v1 = last[1];
        int32_t v2 = last[2];
        int32_t v3 = last[3];
        int32_t v4 = last[4];
        int32_t v5 = last[5];
        int32_t v6 = last[6];
        int32_t v7 = last[7];

        last += 8;

        a += v0 + v1 + v2 + v3 + v4 + v5 + v6 + v7;
        b *= v0 * v1 * v2 * v3 * v4 * v5 * v6 * v7;
      }
      if (len % 8) {
        for (int64_t i = 0; i < len % 8; ++i) {
          a += *last;
          b *= *last;
          last++;
        }
      }
    } else {
      for (int64_t i = 0; i < len; ++i) {
        a += *last;
        b *= *last;
        last++;
      }
    }
  }

  result->begin = (int *)malloc(8);
  result->end = result->begin + 2;
  result->capacity = result->end;
  result->begin[0] = a;
  result->begin[1] = b;
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
    assert (issame(sum_product({}) ,{0, 1}));
    assert (issame(sum_product({1, 1, 1}), {3, 1}));
    assert (issame(sum_product({100, 0}),{100, 0}));
     assert (issame(sum_product({3, 5, 7}) , {3 + 5 + 7, 3 * 5 * 7}));
      assert (issame(sum_product({10}) ,{10, 10}));
}


