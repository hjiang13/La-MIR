```
#include <iostream>
#include <string>

using namespace std;

bool is_equal_to_sum_even(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum % 2 == 0;
}

int main() {
    int num;
    cin >> num;
    if (is_equal_to_sum_even(num)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
```

Note: The decompiled code is in C++, but it can be easily converted to C by removing the `using namespace std;` line and replacing `cout` and `cin` with `printf` and `scanf`, respectively.