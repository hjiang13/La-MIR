#include <iostream>

using namespace std;

int fib(int n) {
    int arr[100];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;

    if (n < 3) {
        return arr[n];
    }

    for (int i = 3; i <= n; ++i) {
        if (i == 4) {
            arr[i] = 1;
            continue;
        }

        if (i % 2 == 1) {
            arr[i] = arr[i - 2] + arr[i - 1];
        } else {
            int prev1 = arr[i - 1];
            int prev2 = arr[i - 2];
            arr[i - 1] = prev1 + prev2;
            arr[i] = arr[i - 1] + prev1;
        }
    }

    return arr[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci number is: " << fib(n) << endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fibfib(2) == 1);
    assert (fibfib(1) == 0);
    assert (fibfib(5) == 4);
    assert (fibfib(8) == 24);
    assert (fibfib(10) == 81);
    assert (fibfib(12) == 274);
    assert (fibfib(14) == 927);
}
