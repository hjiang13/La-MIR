#include <stddef.h>

typedef struct std__vector std_vector;
typedef struct std___Vector_base std___Vector_base;
typedef struct std___Vector_base__Vector_impl std___Vector_base__Vector_impl;
typedef struct std___Vector_base__Vector_impl_data std___Vector_base__Vector_impl_data;
typedef struct std___cxx11__basic_string std___cxx11__basic_string;
typedef struct std___cxx11__basic_string__Alloc_hider std___cxx11__basic_string__Alloc_hider;
typedef union std___cxx11__basic_string_anon std___cxx11__basic_string_anon;

struct std__vector {
  std___Vector_base base;
};

struct std___Vector_base {
  std___Vector_base__Vector_impl impl;
};

struct std___Vector_base__Vector_impl {
  std___Vector_base__Vector_impl_data data;
};

struct std___Vector_base__Vector_impl_data {
  std___cxx11__basic_string *begin;
  std___cxx11__basic_string *end;
  std___cxx11__basic_string *cap;
};

struct std___cxx11__basic_string {
  std___cxx11__basic_string__Alloc_hider _Alloc_hider;
  size_t len;
  std___cxx11__basic_string_anon _anon;
};

struct std___cxx11__basic_string__Alloc_hider {
  char *ptr;
};

union std___cxx11__basic_string_anon {
  size_t _a;
  char _b[8];
};

void total_match(std_vector *result, std_vector *v1, std_vector *v2) {
  std___cxx11__basic_string *v1_end = v1->base.impl.data.end;
  std___cxx11__basic_string *v1_begin = v1->base.impl.data.begin;
  ptrdiff_t v1_len = v1_end - v1_begin;
  if (v1_len == 0) {
    goto match_end;
  }
  size_t v1_size = v1_len / sizeof(std___cxx11__basic_string);
  size_t match_size = (v1_size > 0) ? v1_size : 1;

  std___cxx11__basic_string *v2_end = v2->base.impl.data.end;
  std___cxx11__basic_string *v2_begin = v2->base.impl.data.begin;
  ptrdiff_t v2_len = v2_end - v2_begin;
  if (v2_len == 0) {
    goto match_end;
  }
  size_t v2_size = v2_len / sizeof(std___cxx11__basic_string);
  size_t match_size2 = (v2_size > 0) ? v2_size : 1;

  int v1_total = 0;
  for (size_t i = 0; i < v1_size; ++i) {
    v1_total += v1_begin[i].len;
  }

  int v2_total = 0;
  for (size_t i = 0; i < v2_size; ++i) {
    v2_total += v2_begin[i].len;
  }

  if (v1_total > v2_total) {
    result->base.impl.data.begin = v2_begin;
    result->base.impl.data.end = v2_end;
    result->base.impl.data.cap = v2->base.impl.data.cap;
  } else {
    result->base.impl.data.begin = v1_begin;
    result->base.impl.data.end = v1_end;
    result->base.impl.data.cap = v1->base.impl.data.cap;
  }
  return;

match_end:
  result->base.impl.data.begin = (std___cxx11__basic_string *)0;
  result->base.impl.data.end = (std___cxx11__basic_string *)0;
  result->base.impl.data.cap = (std___cxx11__basic_string *)0;
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
