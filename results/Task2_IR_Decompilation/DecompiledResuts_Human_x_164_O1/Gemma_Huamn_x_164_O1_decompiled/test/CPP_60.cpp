int sum_to_n(int);

int sum_to_n(int n) {
  int n1 = n + 1;
  int n2 = n1 * n;
  int n3 = n2 / 2;
  return n3;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_to_n(1) == 1);
    assert (sum_to_n(6) == 21);
    assert (sum_to_n(11) == 66);
    assert (sum_to_n(30) == 465);
    assert (sum_to_n(100) == 5050);
}
