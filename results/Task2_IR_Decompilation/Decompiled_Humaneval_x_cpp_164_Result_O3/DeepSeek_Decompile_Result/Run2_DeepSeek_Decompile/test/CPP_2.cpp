float truncate_number(float x) {
    int truncated = static_cast<int>(x);
    float truncated_float = static_cast<float>(truncated);
    return x - truncated_float;
}

#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}