int add_elements(const std::vector<int>& v, int n) {
  if (n <= 0) {
    return 0;
  }
  const int* ptr = v.data();
  if (n <= 8) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += ptr[i] + 99;
      if (sum >= 199) {
        sum = 0;
      }
    }
    return sum;
  } else {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 4 * 4; i += 4) {
      int a[4], b[4];
      a[0] = ptr[i] + 99;
      a[1] = ptr[i + 1] + 99;
      a[2] = ptr[i + 2] + 99;
      a[3] = ptr[i + 3] + 99;
      b[0] = ptr[i + 4] + 99;
      b[1] = ptr[i + 5] + 99;
      b[2] = ptr[i + 6] + 99;
      b[3] = ptr[i + 7] + 99;
      if (a[0] < 199) {
        sum1 += a[0];
      }
      if (a[1] < 199) {
        sum1 += a[1];
      }
      if (a[2] < 199) {
        sum1 += a[2];
      }
      if (a[3] < 199) {
        sum1 += a[3];
      }
      if (b[0] < 199) {
        sum2 += b[0];
      }
      if (b[1] < 199) {
        sum2 += b[1];
      }
      if (b[2] < 199) {
        sum2 += b[2];
      }
      if (b[3] < 199) {
        sum2 += b[3];
      }
    }
    sum1 += sum2;
    for (int i = n / 4 * 4; i < n; ++i) {
      sum1 += ptr[i] + 99;
      if (sum1 >= 199) {
        sum1 = 0;
      }
    }
    return sum1;
  }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add_elements({1,-2,-3,41,57,76,87,88,99}, 3) == -4);
    assert (add_elements({111,121,3,4000,5,6}, 2) == 0);
    assert (add_elements({11,21,3,90,5,6,7,8,9}, 4) == 125);
    assert (add_elements({111,21,3,4000,5,6,7,8,9}, 4) == 24);
    assert (add_elements({1}, 1) == 1);
}
