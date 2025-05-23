#include <iostream>
#include <cmath>

using namespace std;

float triangle_area(float base, float height) {
    return (base * height) * 0.5f;
}

int main() {
    float base = 10.0f;
    float height = 5.0f;
    float area = triangle_area(base, height);
    cout << "Area of the triangle: " << area << endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(triangle_area(5, 3) - 7.5)<1e-4);
    assert (abs(triangle_area(2, 2) - 2.0)<1e-4);
    assert (abs(triangle_area(10, 8) - 40.0)<1e-4);
}
