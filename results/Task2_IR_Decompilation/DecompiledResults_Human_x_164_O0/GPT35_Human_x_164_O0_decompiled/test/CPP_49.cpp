#include <iostream>

int mod(int a, int b) {
    int var0;
    int var1;
    int var2;
    int var3;
    
    var0 = a;
    var1 = b;
    var2 = 1;
    var3 = 0;
    
    while (var3 < var0) {
        var2 = (var2 * 2) % var1;
        var3++;
    }
    
    return var2;
}

int main() {
    int a = 10;
    int b = 3;
    int result = mod(a, b);
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (modp(3, 5) == 3);
    assert (modp(1101, 101) == 2);
    assert (modp(0, 101) == 1);
    assert (modp(3, 11) == 8);
    assert (modp(100, 101) == 1);
    assert (modp(30, 5) == 4);
    assert (modp(31, 5) == 3);
}
