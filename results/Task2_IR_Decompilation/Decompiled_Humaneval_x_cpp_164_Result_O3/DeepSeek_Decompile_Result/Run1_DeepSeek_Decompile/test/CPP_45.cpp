#include <iostream>
#include <cmath>

float triangle_area(float base, float height) {
    return (base * height) * 0.5f;
}

int main() {
    float base, height;
    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter height: ";
    std::cin >> height;
    float area = triangle_area(base, height);
    std::cout << "Area of the triangle: " << area << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(triangle_area(5, 3) - 7.5)<1e-4);
    assert (abs(triangle_area(2, 2) - 2.0)<1e-4);
    assert (abs(triangle_area(10, 8) - 40.0)<1e-4);
}
