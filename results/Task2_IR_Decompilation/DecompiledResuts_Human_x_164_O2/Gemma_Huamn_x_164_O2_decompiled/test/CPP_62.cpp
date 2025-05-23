#include <stdlib.h>

void _Z10derivativeSt6vectorIfSaIfEE(float* dest, const float* src) {
  float* dest_begin = dest;
  float* src_begin = (float*)src;
  float* src_end = src_begin + ((src_begin[1] - src_begin[0]) / 4);
  
  if (src_end - src_begin > 1) {
    float* dest_ptr = dest;
    float* src_ptr = src_begin;
    float* src_next = src_begin + 1;
    float* temp_ptr = NULL;
    float* temp_end = NULL;
    float* temp_next = NULL;
    size_t i = 1;
    
    while (src_ptr < src_end) {
      float value = *src_ptr * i;
      if (temp_ptr == temp_end) {
        if (temp_ptr == NULL) {
          temp_ptr = (float*) malloc(sizeof(float) * (src_end - src_begin));
          temp_end = temp_ptr + (src_end - src_begin);
          temp_next = temp_ptr;
        } else {
          size_t new_size = temp_end - temp_ptr;
          if (new_size > 0) {
            new_size *= 2;
          } else {
            new_size = 1;
          }
          temp_ptr = (float*) realloc(temp_ptr, sizeof(float) * new_size);
          temp_end = temp_ptr + new_size;
          temp_next = temp_ptr + (src_ptr - src_begin);
        }
      }
      *temp_next = value;
      temp_next++;
      
      if (src_next < src_end) {
        src_ptr = src_next;
        src_next++;
        i++;
      } else {
        src_ptr++;
      }
    }
    
    float* dest_end = dest_ptr;
    for (float* ptr = temp_ptr; ptr < temp_next; ptr++, dest_ptr++) {
      *dest_ptr = *ptr;
    }

    free(temp_ptr);
    *dest_begin = dest_end - dest;
    dest_ptr = dest_end;

    dest_ptr = dest_begin;
    src_ptr = src_begin;
    src_next = src_begin + 1;
    *dest_ptr = *src_ptr * i;
    i = 1;

    while (src_ptr < src_end) {
      if (src_next < src_end) {
        src_ptr = src_next;
        src_next++;
        i++;
      } else {
        src_ptr++;
      }
      if (dest_ptr < dest_end) {
        *dest_ptr = *src_ptr * i;
        dest_ptr++;
      }
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
    assert (issame(derivative({3, 1, 2, 4, 5}) , {1, 4, 12, 20}));
    assert (issame(derivative({1, 2, 3}) , {2, 6}));
    assert (issame(derivative({3, 2, 1}) , {2, 2}));
    assert (issame(derivative({3, 2, 1, 0, 4}) , {2, 2, 0, 16}));
    assert (issame(derivative({1}) , {}));
}
