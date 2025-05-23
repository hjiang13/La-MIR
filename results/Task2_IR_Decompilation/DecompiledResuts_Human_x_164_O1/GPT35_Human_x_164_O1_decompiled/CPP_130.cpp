```cpp
#include <vector>
#include <iostream>

void tr(int* a, int b) {
    std::vector<int> vec;
    vec.resize(1);
    vec[0] = b;
    *a = vec[0];
}

int main() {
    int a;
    tr(&a, 10);
    std::cout << a << std::endl;
    return 0;
}
```