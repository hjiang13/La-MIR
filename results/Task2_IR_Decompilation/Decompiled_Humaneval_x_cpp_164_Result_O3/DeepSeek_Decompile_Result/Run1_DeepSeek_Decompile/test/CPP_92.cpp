   #include <cmath> // for std::round

   bool any_int(float a, float b, float c) {
       // Check if any of the numbers is not an integer
       bool a_not_int = std::round(a) != a;
       bool b_not_int = std::round(b) != b;
       bool c_not_int = std::round(c) != c;
       
       if (a_not_int || b_not_int || c_not_int) {
           return true;
       }
       
       // If all are integers, check if any two sum to the third
       return (a + b == c) || (a + c == b) || (b + c == a);
   }

#undef NDEBUG
#include<assert.h>
int main(){
    assert (any_int(2, 3, 1)==true);
    assert (any_int(2.5, 2, 3)==false);
    assert (any_int(1.5, 5, 3.5)==false);
    assert (any_int(2, 6, 2)==false);
    assert (any_int(4, 2, 2)==true);
    assert (any_int(2.2, 2.2, 2.2)==false);
    assert (any_int(-4, 6, 2)==true);
    assert (any_int(2,1,1)==true);
    assert (any_int(3,4,7)==true);
    assert (any_int(3.01,4,7)==false);
}
