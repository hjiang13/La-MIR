#include <stdlib.h>

void make_a_pile(void * arg0, int arg1) {
  int *var3;
  void *var4 = arg0;
  memset(var4, 0, 24);
  void *var5 = malloc(4);
  if (var5 == NULL) {
    goto var6;
  }
  int *var7 = var5;
  int *var8 = *(int **)(var4 + 0);
  int var9 = var8 == NULL;
  if (var9 != 0) {
    goto var52;
  }
  *(int **)(var4 + 0) = var7;
  *(int **)(var4 + 8) = var7 + 1;
  *var7 = arg1;
  *(int **)(var4 + 16) = var7 + 1;
  if (arg1 > 1) {
    int var10 = 1;
    for (; var10 < arg1; var10++) {
      var3 = arg0;
      int *var11 = *(int **)(var4 + 16);
      int *var12 = *(int **)(var4 + 0);
      long var13 = (long)var11 - (long)var12;
      long var14 = var13 / 4;
      int *var15 = var12 + var14 - 1;
      int var16 = *var15 + 2;
      int *var17 = var3;
      int var18 = *var17;
      int *var19 = *(int **)(var4 + 16);
      *var19 = var16;
      *(int **)(var4 + 16) = var19 + 1;
    }
  }
  return;

var6:
  var3 = arg0;
  var8 = *(int **)(var4 + 0);
  int var20 = var8 == NULL;
  if (var20 != 0) {
    goto var52;
  }
  free(var8);
  return;

var52:

  return;
}

void * _Znwm(long arg0) {
  return malloc(arg0);
}

void _ZdlPv(void *arg0) {
  free(arg0);
}

void *_ZSt17__throw_bad_allocv() {
  exit(1);
}

void _ZSt20__throw_length_errorPKc(char *arg0) {
  exit(1);
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
    assert (issame(make_a_pile(3) , {3, 5, 7}));
    assert (issame(make_a_pile(4) , {4,6,8,10}));
    assert (issame(make_a_pile(5) , {5, 7, 9, 11, 13}));
    assert (issame(make_a_pile(6) , {6, 8, 10, 12, 14, 16}));
    assert (issame(make_a_pile(8) , {8, 10, 12, 14, 16, 18, 20, 22}));
}
