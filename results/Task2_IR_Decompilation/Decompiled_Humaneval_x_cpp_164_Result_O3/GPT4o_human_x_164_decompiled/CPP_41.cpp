```cpp
#include <iostream>

int car_race_collision(int x) {
    return x * x;
}

int main() {
    int input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    std::cout << "Result: " << car_race_collision(input) << std::endl;
    return 0;
}
```