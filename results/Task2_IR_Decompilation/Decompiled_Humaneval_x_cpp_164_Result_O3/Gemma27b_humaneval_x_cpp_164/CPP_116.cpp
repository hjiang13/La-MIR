```c
#include <stdlib.h>
#include <string.h>

void sort_array(void* obj, void* other) {
  int* arr1 = *(int**)((char*)obj + 16);
  int* arr2 = *(int**)((char*)other + 16);
  int size1 = (char*)arr1 - (char*)obj;
  int size2 = (char*)arr2 - (char*)other;
  int i, j, temp;
  for (i = 0; i < size1; i++) {
    for (j = i + 1; j < size1; j++) {
      if (arr1[i] > arr1[j]) {
        temp = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = temp;
      }
    }
  }
  for (i = 0; i < size2; i++) {
    for (j = i + 1; j < size2; j++) {
      if (arr2[i] > arr2[j]) {
        temp = arr2[i];
        arr2[i] = arr2[j];
        arr2[j] = temp;
      }
    }
  }
  free(arr1);
  free(arr2);
}
```