```c
#include <stdint.h>

struct std___cxx11__basic_string_char__Alloc_hider {
  char* __0;
};

union anon {
  int64_t __0;
  char __1[8];
};

struct std__vector {
  struct std___Vector_base __0;
};

struct std___Vector_base {
  struct std___Vector_base_int_std__allocator_int___Vector_impl __0;
};

struct std___Vector_base_int_std__allocator_int___Vector_impl {
  struct std___Vector_base_int_std__allocator_int___Vector_impl_data __0;
};

struct std___Vector_base_int_std__allocator_int___Vector_impl_data {
  int32_t* __0;
  int32_t* __1;
  int32_t* __2;
};

char const* const .str = "YES";

void _Z8exchangeB5cxx11St6vectorIiSaIiEES1_(
    struct std___cxx11__basic_string_char__Alloc_hider* __0,
    struct std__vector const* __1, struct std__vector const* __2) {
  int32_t* __4 =
      (int32_t*)(((struct std___Vector_base_int_std__allocator_int___Vector_impl* )(void*)__1)->__0.__0 + 1);
  int32_t* __5 =
      (int32_t*)(((struct std___Vector_base_int_std__allocator_int___Vector_impl* )(void*)__1)->__0.__0);
  int64_t __6 = (int64_t)__4;
  int64_t __7 = (int64_t)__5;
  int64_t __8 = __6 - __7;
  int64_t __9 = __8 >> 2;
  if (__8 == 0) {
    goto L15;
  }
  int64_t __10 = __9 > 1 ? __9 : 1;
  goto L28;

L15:
  int32_t __11 = 0;
  int32_t* __12 =
      (int32_t*)(((struct std___Vector_base_int_std__allocator_int___Vector_impl* )(void*)__2)->__0.__0 + 1);
  int32_t* __13 =
      (int32_t*)(((struct std___Vector_base_int_std__allocator_int___Vector_impl* )(void*)__2)->__0.__0);
  int64_t __14 = (int64_t)__12;
  int64_t __15 = (int64_t)__13;
  int64_t __16 = __14 - __15;
  if (__16 == 0) {
    goto L38;
  }
  int64_t __17 = __16 >> 2;
  int64_t __18 = __17 > 1 ? __17 : 1;
  goto L44;
L28:
  int64_t __19 = 0;
  int32_t __20 = 0;
  while (1) {
    int32_t __21 = __5[__19];
    int32_t __22 = __21 & 1;
    int32_t __23 = __22 ^ 1;
    int32_t __24 = __23 + __20;
    __19++;
    if (__19 == __10) {
      goto L15;
    }
  }

L38:

  int32_t __25 = __11;
  int64_t __26 = (int64_t)__25;
  int64_t __27 = __9 > __26 ? __9 : __26;
  union anon* __28 =
      (union anon*)(((struct std___cxx11__basic_string_char__Alloc_hider* )__0)->__0);
  if (__27 > (__26)) {
    goto L59;
  }
L54:
  char* __29 = (char*)__28;
  memcpy(__29, "YES", 3);
  __0->__0.data.size = 3;
  __29[3] = 0;
  goto L64;

L59:

  union anon* __30 =
      (union anon*)(((struct std___cxx11__basic_string_char__Alloc_hider* )__0)->__0);
  __30->__0 = 20302;
  __0->__0.data.size = 2;
  char* __31 = (char*)__30;
  __31[2] = 0;
  goto L64;

L64:
  return;
}
```