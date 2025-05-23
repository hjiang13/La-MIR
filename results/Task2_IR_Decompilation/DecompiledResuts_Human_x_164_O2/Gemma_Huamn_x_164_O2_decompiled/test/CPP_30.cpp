#include <stdint.h>
#include <stdlib.h>

typedef struct {
  float *data;
  float *begin;
  float *end;
} vector_float;

static void vector_float_reserve(vector_float *v, size_t new_capacity) {
  float *new_data = (float *)malloc(new_capacity * sizeof(float));
  size_t old_size = v->end - v->begin;
  for (size_t i = 0; i < old_size; i++) {
    new_data[i] = v->begin[i];
  }
  free(v->data);
  v->data = new_data;
  v->begin = new_data;
  v->end = new_data + old_size;
}

static void vector_float_push_back(vector_float *v, float value) {
  if (v->end == v->data + 2305843009213693951) {
    vector_float_reserve(v, v->end - v->begin + 1);
  }
  *v->end = value;
  v->end++;
}

void get_positive(vector_float *result, vector_float *input) {
  result->data = (float *)calloc(24, sizeof(float));
  result->begin = result->data;
  result->end = result->data;
  for (float *it = input->begin; it != input->end; ++it) {
    if (*it > 0) {
      vector_float_push_back(result, *it);
    }
  }
}

int main() {
  vector_float input = {0};
  vector_float result = {0};
  // ... load input data

  get_positive(&result, &input);

  // ... use result data

  free(input.data);
  free(result.data);
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
    assert (issame(get_positive({-1, -2, 4, 5, 6}) , {4, 5, 6} ));
    assert (issame(get_positive({5, 3, -5, 2, 3, 3, 9, 0, 123, 1, -10}) , {5, 3, 2, 3, 3, 9, 123, 1}));
     assert (issame(get_positive({-1, -2}) , {} ));
     assert (issame(get_positive({}) , {}));
}
