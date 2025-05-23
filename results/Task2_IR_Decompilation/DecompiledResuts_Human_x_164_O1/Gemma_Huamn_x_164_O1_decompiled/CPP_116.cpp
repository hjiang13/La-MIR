```c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct __anon_0 {
  int *data;
  int *begin;
  int *end;
} std_vector;

void _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(std_vector *this_, int *pos, int *value) {
  int *end = this_->end;
  int *begin = this_->begin;
  long int size = (long int)(end - begin);
  int is_full = size ==