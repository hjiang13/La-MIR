#include <stdint.h>
#include <stddef.h>

void incr_list(int *ret_vec, int *vec) {
  int *end = vec + (vec[1] - vec[0]) / 4;
  for (int *p = vec; p < end; ++p) {
    *p = *p + 1;
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
