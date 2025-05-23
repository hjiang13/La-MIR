#include <iostream>

float triangle_areaff(float a, float b) {
    float result;
    result = a * b;
    result *= 0.5f;
    return result;
}

int main() {
    float side1 = 3.0f;
    float side2 = 4.0f;
    
    float area = triangle_areaff(side1, side2);
    
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
