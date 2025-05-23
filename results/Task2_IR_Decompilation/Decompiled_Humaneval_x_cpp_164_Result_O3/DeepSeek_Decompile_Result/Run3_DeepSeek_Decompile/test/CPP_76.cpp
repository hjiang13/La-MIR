#include <iostream>

bool is_simple_power(int base, int exp) {
    if (base <= 0) return false;
    
    int result = 1;
    int i = 0;
    
    while (true) {
        if (result > base) return false;
        if (result == base) return true;
        
        if (i >= 99) return false; // Prevent infinite loops
        
        result *= exp;
        i++;
    }
    
    return false;
}

int main() {
    // Example usage:
    std::cout << std::boolalpha;
    std::cout << is_simple_power(8, 2) << std::endl;  // true (2^3=8)
    std::cout << is_simple_power(10, 2) << std::endl; // false
    std::cout << is_simple_power(1, 5) << std::endl;  // true (5^0=1)
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
