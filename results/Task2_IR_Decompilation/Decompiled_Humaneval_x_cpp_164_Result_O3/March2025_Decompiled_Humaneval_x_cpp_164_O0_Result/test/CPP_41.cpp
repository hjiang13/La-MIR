int car_race_collision(int param) {
    int temp = param;
    int result = temp * temp;
    return result;
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
