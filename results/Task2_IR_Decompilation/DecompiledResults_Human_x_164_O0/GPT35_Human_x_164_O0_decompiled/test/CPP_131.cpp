#include <string>
#include <iostream>

int digits(int num) {
    std::string str = std::to_string(num);
    int count = 0;
    
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if ((c - '0') % 2 == 1) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int num = 123456789;
    int result = digits(num);
    std::cout << "Number of odd digits in " << num << " is: " << result << std::endl;
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (digits(5) == 5);
    assert (digits(54) == 5);
    assert (digits(120) ==1);
    assert (digits(5014) == 5);
    assert (digits(98765) == 315);
    assert (digits(5576543) == 2625);
    assert (digits(2468) == 0);
}
