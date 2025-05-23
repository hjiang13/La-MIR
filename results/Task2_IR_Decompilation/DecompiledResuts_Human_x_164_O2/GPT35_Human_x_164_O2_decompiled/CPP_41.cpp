```c
#include <iostream>

int car_race_collision(int x) {
    int result = x * x;
    return result;
}

int main() {
    int input = 5;
    int output = car_race_collision(input);
    std::cout << "Output: " << output << std::endl;
    return 0;
}
```