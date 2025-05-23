extern "C" float truncate_number(float input) {
    int truncated = static_cast<int>(input);
    float result = input - static_cast<float>(truncated);
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}