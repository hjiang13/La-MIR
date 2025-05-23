#include <iostream>
#include <string>

using namespace std;

float truncate_number(float number) {
    float truncated_number = 0;
    int truncated_int = (int)number;
    truncated_number = (float)truncated_int;
    return truncated_number;
}

int main() {
    float number = 3.14159;
    float truncated_number = truncate_number(number);
    cout << "Truncated number: " << truncated_number << endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}