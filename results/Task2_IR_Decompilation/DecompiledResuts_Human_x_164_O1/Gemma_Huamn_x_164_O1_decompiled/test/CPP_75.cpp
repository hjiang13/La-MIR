int _Z17is_multiply_primei(int);

int _Z17is_multiply_primei(int  ) {
  if (  < 4) {
    return  == 2;
  }
  int  = 2;
  int  = 0;
  int  = ;
  while (1) {
    int  =  % ;
    if ( == 0 &&  > ) {
      int  = 0;
      int  = ;
      while (1) {
        int  =  / ;
        ++ ;
        int  =  % ;
        if ( == 0 &&  > ) {
          continue;
        }
        break;
      }
    }
    ++ ;
    int  =  * ;
    if ( > ) {
      break;
    }
  }
  return  == 2;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_multiply_prime(5) == false);
    assert (is_multiply_prime(30) == true);
    assert (is_multiply_prime(8) == true);
    assert (is_multiply_prime(10) == false);
    assert (is_multiply_prime(125) == true);
    assert (is_multiply_prime(3 * 5 * 7) == true);
    assert (is_multiply_prime(3 * 6 * 7) == false);
    assert (is_multiply_prime(9 * 9 * 9) == false);
    assert (is_multiply_prime(11 * 9 * 9) == false);
    assert (is_multiply_prime(11 * 13 * 7) == true);
}
