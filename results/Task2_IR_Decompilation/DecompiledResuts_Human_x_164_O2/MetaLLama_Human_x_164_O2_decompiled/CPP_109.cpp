typedef struct {
  int* _M_start;
  int* _M_finish;
  int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
  _Vector_impl_data _M_impl;
} _Vector_base;

typedef struct {
  _Vector_base _M_base;
} std_vector;

int llvm_vector_reduce_add_v4i32(int a, int b, int c, int d) {
  return a + b + c + d;
}

int move_one_ball(std_vector* v) {
  int* start = v->_M_base._M_impl._M_start;
  int* end = v->_M_base._M_impl._M_finish;
  int len = (end - start) / sizeof(int);
  if (len == 0)
    return 1;

  int res = 0;
  int x = *start;
  if (len > 1) {
    int tail_len = len - (len & ~7);
    int* tail_start = start + tail_len;
    int tail_x = x;
    int tail_res = 0;
    while (tail_start < end) {
      int y = *tail_start;
      tail_res += y < tail_x;
      tail_x = y;
      tail_start++;
    }
    res += tail_res;
    len = tail_len;
  }

  int* aligned_end = start + (len & ~7);
  while (start < aligned_end) {
    int y0 = start[0];
    int y1 = start[1];
    int y2 = start[2];
    int y3 = start[3];
    int y4 = start[4];
    int y5 = start[5];
    int y6 = start[6];
    int y7 = start[7];
    res += y0 < x;
    res += y1 < y0;
    res += y2 < y1;
    res += y3 < y2;
    res += y4 < y3;
    res += y5 < y4;
    res += y6 < y5;
    res += y7 < y6;
    x = y7;
    start += 8;
  }

  return res < 2;
}
