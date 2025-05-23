```c
#include <iostream>

int add(int a, int b) {
    int result;
    result = a + b;
    return result;
}

int main() {
    int num1 = 5;
    int num2 = 10;
    
    int sum = add(num1, num2);
    
    std::cout << "Sum: " << sum << std::endl;
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add(0, 1) == 1);
    assert (add(1, 0) == 1);
    assert (add(2, 3) == 5);
    assert (add(5, 7) == 12);
    assert (add(7, 5) == 12);
    for (int i=0;i<100;i+=1)
    {
        int x=rand()%1000;
        int y=rand()%1000;
        assert (add(x, y) == x + y);
    }
}
