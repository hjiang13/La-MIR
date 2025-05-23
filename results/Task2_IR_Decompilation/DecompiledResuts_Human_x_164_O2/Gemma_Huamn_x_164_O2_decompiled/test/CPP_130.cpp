#include <stdlib.h>

typedef struct {
  int *data;
  int size;
  int capacity;
} vector;

void trii(vector *out, int n) {
  out->data = (int *)malloc(8);
  out->data[0] = 1;
  out->data[1] = 3;
  if (n == 0) {
    out->size = 0;
    out->capacity = 0;
    return;
  }
  if (n < 2) {
    out->size = n;
    out->capacity = 2;
    return;
  }
  int *tmp = malloc(sizeof(int) * (n + 1));
  tmp[0] = 1;
  tmp[1] = 3;
  int i = 2;
  for (; i < n; ++i) {
    tmp[i] = tmp[i - 1] + tmp[i - 2];
  }
  free(out->data);
  out->data = tmp;
  out->size = n;
  out->capacity = n;
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
    assert (issame(tri(3) , {1, 3, 2, 8}));
    assert (issame(tri(4) , {1, 3, 2, 8, 3}));
    assert (issame(tri(5) , {1, 3, 2, 8, 3, 15}));
    assert (issame(tri(6) , {1, 3, 2, 8, 3, 15, 4}));
    assert (issame(tri(7) , {1, 3, 2, 8, 3, 15, 4, 24}));
    assert (issame(tri(8) , {1, 3, 2, 8, 3, 15, 4, 24, 5}));
    assert (issame(tri(9) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35}));
    assert (issame(tri(20) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35, 6, 48, 7, 63, 8, 80, 9, 99, 10, 120, 11}));
    assert (issame(tri(0) , {1}));
    assert (issame(tri(1) , {1, 3}));
}
