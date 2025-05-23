#include <iostream>

bool any_int(float a, float b, float c) {
    // Check if any of the numbers is not an integer
    if (a != static_cast<float>(static_cast<int>(a)) ||
        b != static_cast<float>(static_cast<int>(b)) ||
        c != static_cast<float>(static_cast<int>(c))) {
        return true;
    }
    
    // Check if any two numbers sum to the third
    if ((a + b == c) || (a + c == b) || (b + c == a)) {
        return true;
    }
    
    return false;
}

int main() {
    // Example usage:
    std::cout << std::boolalpha;
    std::cout << any_int(1.0f, 2.0f, 3.0f) << std::endl;   // Should print: true (1+2=3)
    std::cout << any_int(1.5f, 2.0f, 3.0f) << std::endl;   // Should print: true (1.5 is not integer)
    std::cout << any_int(1.0f, 2.0f, 2.0f) << std::endl;   // Should print: false
    return 0;
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
