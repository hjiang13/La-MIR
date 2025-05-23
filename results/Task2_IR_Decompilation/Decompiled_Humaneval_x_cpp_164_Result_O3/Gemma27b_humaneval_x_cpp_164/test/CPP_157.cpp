float _Z20right_angle_trianglefff(float, float, float);

float _Z20right_angle_trianglefff(float  arg0, float  arg1, float  arg2){
  float  var4 = arg0 * arg0;
  float  var5 = arg1 * arg1;
  float  var6 = var4 + var5;
  float  var7 = arg2 * arg2;
  float  var8 = var6 - var7;
  double var9 = fabs(var8);
  if (var9 < 0.0001) {
    return 1;
  }
  float var13 = var4 + var7;
  float var14 = var13 - var5;
  double var15 = fabs(var14);
  if (var15 < 0.0001) {
    return 1;
  }
  float var19 = var5 + var7;
  float var20 = var19 - var4;
  double var21 = fabs(var20);
  if (var21 < 0.0001) {
    return 1;
  }
  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (right_angle_triangle(3, 4, 5) == true);
    assert (right_angle_triangle(1, 2, 3) == false);
    assert (right_angle_triangle(10, 6, 8) == true);
    assert (right_angle_triangle(2, 2, 2) == false);
    assert (right_angle_triangle(7, 24, 25) == true);
    assert (right_angle_triangle(10, 5, 7) == false);
    assert (right_angle_triangle(5, 12, 13) == true);
    assert (right_angle_triangle(15, 8, 17) == true);
    assert (right_angle_triangle(48, 55, 73) == true);
    assert (right_angle_triangle(1, 1, 1) == false);
    assert (right_angle_triangle(2, 2, 10) == false);
}
