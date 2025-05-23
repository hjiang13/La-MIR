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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (car_race_collision(2) == 4);
    assert (car_race_collision(3) == 9);
    assert (car_race_collision(4) == 16);
    assert (car_race_collision(8) == 64);
    assert (car_race_collision(10) == 100);
}
