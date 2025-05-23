```cpp
#include <vector>
#include <stdexcept>

void factorize(std::vector<int>& vec, int num) {
    if (num < 4) {
        vec.clear();
        return;
    }

    int div = 2;
    while (num % div != 0) {
        div++;
    }

    vec.push_back(div);
    factorize(vec, num / div);
}

int main() {
    std::vector<int> factors;
    int number = 123456; // Specify the number to factorize here
    factorize(factors, number);

    for (int factor : factors) {
        printf("%d ", factor);
    }

    return 0;
}
```