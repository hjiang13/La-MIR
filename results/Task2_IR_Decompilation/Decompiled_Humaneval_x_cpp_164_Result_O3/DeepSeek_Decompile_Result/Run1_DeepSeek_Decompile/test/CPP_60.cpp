#include <iostream>

int sum_to_n(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n = 10; // Example input
    int result = sum_to_n(n);
    std::cout << "The sum of the first " << n << " natural numbers is: " << result << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_to_n(1) == 1);
    assert (sum_to_n(6) == 21);
    assert (sum_to_n(11) == 66);
    assert (sum_to_n(30) == 465);
    assert (sum_to_n(100) == 5050);
}
