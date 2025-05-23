```cpp
#include <iostream>

long long special_factorial(int num) {
    if (num < 1) {
        return 1;
    }
    
    int new_num = num + 1;
    long long result = 1;
    
    for (int i = 1; i <= new_num; i++) {
        result *= i;
    }
    
    return result;
}

int main() {
    int input = 5;
    std::cout << special_factorial(input) << std::endl;
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}
