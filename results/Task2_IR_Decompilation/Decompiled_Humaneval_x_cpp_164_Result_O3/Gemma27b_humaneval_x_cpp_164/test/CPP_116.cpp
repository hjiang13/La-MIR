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
    assert (issame(sort_array({1,5,2,3,4}) , {1, 2, 4, 3, 5}));
    assert (issame(sort_array({-2,-3,-4,-5,-6}) , {-4, -2, -6, -5, -3}));
    assert (issame(sort_array({1,0,2,3,4}) , {0, 1, 2, 4, 3}));
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({2,5,77,4,5,3,5,7,2,3,4}) , {2, 2, 4, 4, 3, 3, 5, 5, 5, 7, 77}));
    assert (issame(sort_array({3,6,44,12,32,5}) , {32, 3, 5, 6, 12, 44}));
    assert (issame(sort_array({2,4,8,16,32}) , {2, 4, 8, 16, 32}));
    assert (issame(sort_array({2,4,8,16,32}) , {2, 4, 8, 16, 32}));
}
