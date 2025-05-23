#include <iostream>

bool is_simple_power(int a, int b) {
    if (a <= 0) return false;
    if (a == 1) return (b == 1);
    
    int count = 0;
    int power = 1;
    
    while (power <= a && count < 99) {
        power *= b;
        count++;
        if (power == a) return true;
    }
    
    return false;
}

int main() {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;
    if (is_simple_power(a, b)) {
        std::cout << a << " is a power of " << b << std::endl;
    } else {
        std::cout << a << " is not a power of " << b << std::endl;
    }
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_simple_power(1, 4)== true);
    assert (is_simple_power(2, 2)==true);
    assert (is_simple_power(8, 2)==true);
    assert (is_simple_power(3, 2)==false);
    assert (is_simple_power(3, 1)==false);
    assert (is_simple_power(5, 3)==false);
    assert (is_simple_power(16, 2)== true);
    assert (is_simple_power(143214, 16)== false);
    assert (is_simple_power(4, 2)==true);
    assert (is_simple_power(9, 3)==true);
    assert (is_simple_power(16, 4)==true);
    assert (is_simple_power(24, 2)==false);
    assert (is_simple_power(128, 4)==false);
    assert (is_simple_power(12, 6)==false);
    assert (is_simple_power(1, 1)==true);
    assert (is_simple_power(1, 12)==true);
}
