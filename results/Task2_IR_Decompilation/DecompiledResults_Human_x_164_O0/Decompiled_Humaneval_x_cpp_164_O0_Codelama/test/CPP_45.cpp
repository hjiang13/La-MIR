#include <iostream>
#include <string>

using namespace std;

float triangle_area(float base, float height) {
    return (base * height) / 2;
}

int main() {
    float base, height;
    cout << "Enter the base and height of the triangle: ";
    cin >> base >> height;
    cout << "The area of the triangle is: " << triangle_area(base, height) << endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(triangle_area(5, 3) - 7.5)<1e-4);
    assert (abs(triangle_area(2, 2) - 2.0)<1e-4);
    assert (abs(triangle_area(10, 8) - 40.0)<1e-4);
}
