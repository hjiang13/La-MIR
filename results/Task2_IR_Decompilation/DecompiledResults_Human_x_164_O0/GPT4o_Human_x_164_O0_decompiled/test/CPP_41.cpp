#include <iostream>

extern "C" int car_race_collision(int input) {
    return input * input;
}

int main() {
    int input = 5; // Example input
    std::cout << "Result: " << car_race_collision(input) << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (car_race_collision(2) == 4);
    assert (car_race_collision(3) == 9);
    assert (car_race_collision(4) == 16);
    assert (car_race_collision(8) == 64);
    assert (car_race_collision(10) == 100);
}
