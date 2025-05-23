#include <stdint.h>

void incr_list(int* sret, int* arg) {
  int* end = arg + ((int*)(arg + 1) - arg);
  int* begin = arg;
  while (begin != end) {
    *begin++ += 1;
  }
  int* sret_begin = begin;
  int* sret_end = end;
  sret = begin;
  sret_begin = end;
  sret_end = end;
  for (int i = 0; i < 24; ++i) {
    *(((char*)arg) + i) = 0;
  }
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
    assert (issame(incr_list({}) , {}));
    assert (issame(incr_list({3, 2, 1}) , {4, 3, 2}));
    assert (issame(incr_list({5, 2, 5, 2, 3, 3, 9, 0, 123}) , {6, 3, 6, 3, 4, 4, 10, 1, 124}));
}
