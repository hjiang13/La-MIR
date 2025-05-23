#include <stdlib.h>
#include <string.h>

typedef struct std_vector {
  int *data;
  int size;
  int capacity;
} std_vector;

void _Z11count_up_toi(std_vector *v, int n) {
  int i;
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
  i = 2;
  if (n > 2) {
    while (i < n) {
      int *p = v->data;
      int *q = p;
      int s = v->size;
      int c = v->capacity;
      if (p == q) {
        c = 0;
      } else {
        while (q != p) {
          c++;
          q++;
        }
      }
      if (s > c) {
        c = s;
      }
      int j;
      for (j = 0; j < c; j++) {
        if (i % (p[j] * p[j]) == 0) {
          break;
        }
      }
      if (j == c) {
        if (p == v->data && v->capacity == 0) {
          v->data = (int *)malloc(sizeof(int) * 1);
          v->capacity = 1;
        } else if (v->size == v->capacity) {
          int *new_data = (int *)malloc(sizeof(int) * (v->capacity * 2));
          memcpy(new_data, v->data, sizeof(int) * v->size);
          free(v->data);
          v->data = new_data;
          v->capacity *= 2;
        }
        v->data[v->size] = i;
        v->size++;
      }
      i++;
    }
  }
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
    assert (issame(count_up_to(5) , {2,3}));
    assert (issame(count_up_to(6) , {2,3,5}));
    assert (issame(count_up_to(7) , {2,3,5}));
    assert (issame(count_up_to(10) , {2,3,5,7}));
    assert (issame(count_up_to(0) , {}));
    assert (issame(count_up_to(22) , {2,3,5,7,11,13,17,19}));
    assert (issame(count_up_to(1) , {}));
    assert (issame(count_up_to(18) , {2,3,5,7,11,13,17}));
    assert (issame(count_up_to(47) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}));
    assert (issame(count_up_to(101) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}));
}
