#include <stdio.h>

void rescale_to_unit(float* dst, float* src, int n) {
  float min = 1e5;
  float max = -1e5;
  for (int i = 0; i < n; i++) {
    float val = src[i];
    if (val < min) {
      min = val;
    }
    if (val > max) {
      max = val;
    }
  }
  float range = max - min;
  for (int i = 0; i < n; i++) {
    dst[i] = (src[i] - min) / range;
  }
}

int main() {
  float src[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  float dst[5];

  rescale_to_unit(dst, src, 5);

  for (int i = 0; i < 5; i++) {
    printf("%f ", dst[i]);
  }
  printf("\n");
  return 0;
}


#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(rescale_to_unit({2.0, 49.9}) , {0.0, 1.0}));
     assert (issame(rescale_to_unit({100.0, 49.9}) ,{1.0, 0.0})); 
     assert (issame(rescale_to_unit({1.0, 2.0, 3.0, 4.0, 5.0}) , {0.0, 0.25, 0.5, 0.75, 1.0}));
    assert (issame(rescale_to_unit({2.0, 1.0, 5.0, 3.0, 4.0}) , {0.25, 0.0, 1.0, 0.5, 0.75}));
     assert (issame(rescale_to_unit({12.0, 11.0, 15.0, 13.0, 14.0}) ,{0.25, 0.0, 1.0, 0.5, 0.75}));
}
