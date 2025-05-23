#include <iostream>

using namespace std;

int largest_divisor(int n) {
    if (n < 4) {
        return 1;
    }

    int largest = 1;
    int divisor = 2;

    do {
        if (n % divisor == 0) {
            largest = n / divisor;
        }
        divisor++;
    } while (divisor * divisor <= n);

    return largest;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Largest divisor of " << num << " is " << largest_divisor(num) << endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_divisor(3) == 1);
    assert (largest_divisor(7) == 1);
    assert (largest_divisor(10) == 5);
    assert (largest_divisor(100) == 50);
    assert (largest_divisor(49) == 7);
}
