```c
#include <stdio.h>

void intersectionB5cxx11St6vectorIiSaIiEES1_(char * out, int * in1, int * in2)
{
  int *ptr1 = in1;
  int *ptr2 = in2;
  int size1 = *ptr1;
  int size2 = *ptr2;
  int minSize = size1 < size2 ? size1 : size2;
  ptr1++;
  ptr2++;
  int sizeDiff = *ptr2 - *ptr1;
  int sizeDiff2 = sizeDiff < 2 ? 2 : sizeDiff;
  if (sizeDiff2 < 4) {
    sprintf(out, "YES");
  } else {
    int i = 0;
    int sizeDiff3 = sizeDiff2 * sizeDiff2;
    while (sizeDiff3 > sizeDiff2) {
      i++;
      sizeDiff3 = i * i;
    }
    int remainder = sizeDiff2 % i;
    if (remainder == 0) {
      sprintf(out, "YES");
    } else {
      sprintf(out, "NO");
    }
  }
}