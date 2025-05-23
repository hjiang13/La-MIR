#include <stdint.h>

void _Z9incr_listSt6vectorIiSaIiEE(int* out, int* in) {
  int* end = in + (in[1] - in[0]) / 4;
  for (; in < end; in += 4) {
    *(in) += 1;
    *(in + 1) += 1;
    *(in + 2) += 1;
    *(in + 3) += 1;
  }
  if ((in[1] - in[0]) % 4 != 0) {
    for (; in < end + ((in[1] - in[0]) % 4); in++) {
      *in += 1;
    }
  }
  out = in;
  out[1] = end;
  out[2] = end;

  for (int i = 0; i < 24 / sizeof(int); i++) {
    in[i] = 0;
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
    assert (issame(incr_list({}) , {}));
    assert (issame(incr_list({3, 2, 1}) , {4, 3, 2}));
    assert (issame(incr_list({5, 2, 5, 2, 3, 3, 9, 0, 123}) , {6, 3, 6, 3, 4, 4, 10, 1, 124}));
}
