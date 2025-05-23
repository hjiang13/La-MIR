```
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
```

Note: The decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same functionality.