```c
#include <stdio.h>

int car_race_collision(int param) {
    int result = param * param;
    return result;
}

int main() {
    int input = 5;
    int output = car_race_collision(input);
    printf("Result: %d\n", output);
    return 0;
}
```