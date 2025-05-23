```cpp
#include <iostream>

extern "C" int car_race_collision(int input) {
    return input * input;
}

int main() {
    int input = 5; // Example input
    std::cout << "Result: " << car_race_collision(input) << std::endl;
    return 0;
}
```