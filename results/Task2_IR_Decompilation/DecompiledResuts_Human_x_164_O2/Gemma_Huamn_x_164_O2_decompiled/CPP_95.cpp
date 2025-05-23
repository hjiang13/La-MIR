```c
#include <stdint.h>

struct std__cxx11__basic_string {
  struct std__cxx11__basic_string__Alloc_hider _Alloc_hider;
  int64_t _M_length;
  union anon {
    int64_t _M_capacity;
    char _M_bytes[8];
  } _M_data;
};

struct std__Rb_tree_node_base {
  int32_t          _M_color;
  struct std__Rb_tree_node_base* _M_parent;
  struct std__Rb_tree_node_base* _M_left;
  struct std__Rb_tree_node_base* _M_right;
};

struct std__Rb_tree_header {
  struct std__Rb_tree_node_base _M_header;
  int64_t _M_node_count;
};

struct std__Rb_tree_key_compare {
  struct std__less _M_key_compare;
};

struct std__less {
  char _M_unused;
};

struct std__map {
  struct std__Rb_tree _M_t;
};

struct std__Rb_tree {
  struct std__Rb_tree_key_compare _M_key_compare;
  struct std__Rb_tree_header _M_header;
};

int check_dict_case(struct std__map* arg_0) {
  int64_t _2;
  struct std__cxx11__basic_string _3;
  struct std__Rb_tree_node_base* _4 = (struct std__Rb_tree_node_base*)(((char*)arg_0) + 40);
  int64_t _5 = *(int64_t*)(((char*)_4) + 24);
  if (_5 == 0) {
    return 0;
  }

  struct std__Rb_tree_node_base* _6 = *(struct std__Rb_tree_node_base**)(((char*)_4) + 8);
  struct std__Rb_tree_node_base* _7 = *(struct std__Rb_tree_node_base**)(((char*)_4) + 0);
  struct std__Rb_tree_node_base* _8 = _6;
  int32_t _9 = 0;
  int32_t _10 = 0;

  while (_8 != _7) {
    struct std__Rb_tree_node_base* _11 = (struct std__Rb_tree_node_base*)(((char*)_8) + 16);
    _3._Alloc_hider._M_ptr = (char*)(((char*)_11) + 0);
    _3._M_length = *(int64_t*)(((char*)_11) + 8);
    _3._M_capacity = *(int64_t*)(((char*)_11) + 8);

    if (_3._M_length > 15) {
      _3._M_ptr = (char*)malloc(_3._M_length + 1);

      _3._M_capacity = _3._M_length;
    }

    char* _12 = (char*)_3._M_ptr;
    switch (_3._M_length) {
      case 1:
        *_12 = *(((char*)_11) + 0);
        break;

      case 0:
        break;

      default:
        memcpy(_12, ((char*)_11) + 0, _3._M_length);
    }
    *(int64_t*)(((char*)&_3) + 8) = _3._M_length;

    int32_t _13 = _3._M_length;
    if (_13 == 0 || _3._M_ptr == (char*)(((char*)_11) + 0)) {

    }

    int32_t _14 = _9;
    int32_t _15 = _10;

    if (_13 == 0) {
      break;
    }

    int32_t _16 = 0;
    int32_t _17 = 0;

    int32_t _18 = 0;
    int32_t _19 = 0;

    while (_18 < _13) {
      char _20 = *(_12 + _18);

      if (_20 < 65) {
        break;
      }

      if (_20 > 90) {
        _17 = 1;
        if (_20 - 97 > 25) {
          break;
        }
      }
      _19 = 1;
      _18++;
    }

    if (_17 != _19) {
      _16 = _14;
      _15 = _16 + _19;
    }

    if (_15 == 2) {
      break;
    }

    _8 = (struct std__Rb_tree_node_base*)(((char*)_8) + 32);

    _9 = _16;
    _10 = _15;
  }

  return _10 != 0;
}

```