```c
int fizz_buzzi(int param) {
  int var1;
  int var2;
  int var3;
  int var4;
  
  var1 = param;
  var2 = 0;
  var3 = 0;
  var4 = 0;
  
  while(1) {
    if (var4 < var1) {
      if (var4 % 11 == 0) {
        if (var4 % 13 != 0) {
          var3 = var4;
          while(var3 > 0) {
            if (var3 % 10 == 7) {
              var2++;
            }
            var3 = var3 / 10;
          }
        }
      }
    } else {
      break;
    }
    var4++;
  }
  
  return var2;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fizz_buzz(50) == 0);
    assert (fizz_buzz(78) == 2);
    assert (fizz_buzz(79) == 3);
    assert (fizz_buzz(100) == 3);
    assert (fizz_buzz(200) == 6);
    assert (fizz_buzz(4000) == 192);
    assert (fizz_buzz(10000) == 639);
    assert (fizz_buzz(100000) == 8026);
}
