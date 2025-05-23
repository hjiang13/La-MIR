#include <stdint.h>

typedef struct{
  void * _Vec_impl;
  void * _Vec_impl_data;
} std_vector;

typedef struct{
  void * _M_dataplus;
  size_t _M_len;
  size_t _M_cap;
} std_string;

void total_match(std_vector *res, const std_vector *v1, const std_vector *v2) {
  std_string *beg1 = *(std_string **)(((char *)v1) + 16);
  std_string *end1 = beg1 + ((*(std_string **)v1) - beg1);
  std_string *beg2 = *(std_string **)(((char *)v2) + 16);
  std_string *end2 = beg2 + ((*(std_string **)v2) - beg2);

  int sum1 = 0;
  if (end1 != beg1) {
    for (std_string *p = beg1; p != end1; ++p) {
      sum1 += *(int *)(((char *)p) + 8);
    }
  }
  
  int sum2 = 0;
  if (end2 != beg2) {
    for (std_string *p = beg2; p != end2; ++p) {
      sum2 += *(int *)(((char *)p) + 8);
    }
  }
  
  const std_vector *winner = sum1 > sum2 ? v1 : v2;
  const std_string *winner_beg = winner == v1 ? beg1 : beg2;
  const std_string *winner_end = winner == v1 ? end1 : end2;

  *(std_string **)res = winner_beg;
  *((std_string **)res + 1) = winner_end;
  *((std_string **)res + 2) = *(std_string **)(((char *)winner) + 24);

}

#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(total_match({}, {}) , {}));
    assert (issame(total_match({"hi", "admin"}, {"hi", "hi"}) , {"hi", "hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hi", "hi", "admin", "project"}) , {"hi", "admin"}));
    assert (issame(total_match({"4"}, {"1", "2", "3", "4", "5"}) , {"4"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "Hi"}) , {"hI", "Hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "hi", "hi"}) , {"hI", "hi", "hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "hi", "hii"}) , {"hi", "admin"}));
    assert (issame(total_match({}, {"this"}) , {}));
    assert (issame(total_match({"this"}, {}) , {}));
}
