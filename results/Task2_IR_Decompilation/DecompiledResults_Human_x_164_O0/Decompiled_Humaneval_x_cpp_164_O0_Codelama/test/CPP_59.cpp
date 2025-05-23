#include <iostream>
#include <string>

using namespace std;

int largest_prime_factor(int n) {
    int i = 2;
    while (i <= n / i) {
        if (n % i == 0) {
            n = n / i;
        } else {
            i++;
        }
    }
    return n;
}

int main() {
    int n;
    cin >> n;
    cout << largest_prime_factor(n) << endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_prime_factor(15) == 5);
    assert (largest_prime_factor(27) == 3);
    assert (largest_prime_factor(63) == 7);
    assert (largest_prime_factor(330) == 11);
    assert (largest_prime_factor(13195) == 29);
}
