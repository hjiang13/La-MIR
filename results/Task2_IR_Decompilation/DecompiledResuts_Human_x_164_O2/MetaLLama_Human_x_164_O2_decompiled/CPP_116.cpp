#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _Z10sort_arraySt6vectorIiSaIiEE(void *a, void *b) {
  int *p, *q, *r, *s, *t;
  long i, j, k, l;
  int x, y;

  p = (int *)b + 1;
  q = (int *)b;
  r = (int *)b;
  s = (int *)b + 1;
  t = (int *)b + 1;

  if (p == q) {
    goto label98;
  }

  i = 0;
  j = 0;
  k = 0;
  l = 0;
  x = 0;
  y = 0;

label11:
  if (i >= l) {
    goto label98;
  }

  if (j == k) {
    goto label34;
  }

  x = abs(*(int *)r);
  y = 0;

label23:
  if (x < 2) {
    goto label30;
  }

  y += x & 1;
  x >>= 1;
  goto label23;

label30:
  if (y == 0) {
    goto label34;
  }

label33:
  *(int *)t = y;
  goto label71;

label34:
  s = (int *)malloc((l - i) * 4);
  if (!s) {
    _ZSt20__throw_length_errorPKc("vector::_M_realloc_insert");
  }

  if (l - i > 0) {
    memmove(s, r, (l - i) * 4);
  }

  if (t != 0) {
    free(t);
  }

label67:
  r = s;
  s += l - i;
  q = (int *)b + 1;
  l = (long)p - (long)q;

label71:
  if (l > i) {
    i++;
    r++;
    goto label11;
  }

label8:
  if (l <= 1) {
    goto label98;
  }

label94:
  j = 0;
  if (l > 1) {
    j = 1;
  }

label96:
  x = *r;
  r++;
  if (j == l) {
    goto label98;
  }

label115:
  if (j > 1) {
    if (*(int *)s < x) {
      int temp = *s;
      *s = x;
      x = temp;
    }
  }

label128:
  if (j > 1) {
    if (*(int *)s <= x) {
      int temp = *s;
      *s = x;
      x = temp;
    }
  }

label143:
  j++;
  if (j == l) {
    goto label112;
  }
  goto label115;

label112:
  if (j == l) {
    goto label98;
  }
  goto label94;

label98:
  p = q;
  q = (int *)b;
  r = 0;
  s = (int *)b;
  t = (int *)b + 1;
  return;
}
