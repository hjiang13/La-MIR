#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int *end;
    int *capacity;
} vector_t;

void _ZNSt6vectorIiSaIiEE13_M_assign_auxIPKiEEvT_S5_St20forward_iterator_tag(vector_t *this, int *first, int *last) {
    size_t count = (last - first) * sizeof(int);
    if (this->end - this->data > count) {
      memmove(this->data, first, count);
      this->end = this->data + count / sizeof(int);
      return;
    }
    
    this->data = realloc(this->data, count);
    if (this->data == NULL) {
      exit(1);
    }
    this->end = this->data + count / sizeof(int);
    this->capacity = this->end;
    memcpy(this->data, first, count);
}

void _Z5pluckSt6vectorIiSaIiEE(vector_t *this, const vector_t *other) {
  int *first = other->data;
  int *last = other->end;
  this->data = NULL;
  this->end = NULL;
  this->capacity = NULL;
  _ZNSt6vectorIiSaIiEE13_M_assign_auxIPKiEEvT_S5_St20forward_iterator_tag(this, first, last);
}

int main() {
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
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}
