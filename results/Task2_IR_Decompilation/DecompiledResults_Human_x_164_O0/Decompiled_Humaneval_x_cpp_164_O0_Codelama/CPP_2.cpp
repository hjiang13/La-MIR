```
#include <iostream>
#include <string>

using namespace std;

float truncate_number(float number) {
    float truncated_number = 0;
    int truncated_int = (int)number;
    truncated_number = (float)truncated_int;
    return truncated_number;
}

int main() {
    float number = 3.14159;
    float truncated_number = truncate_number(number);
    cout << "Truncated number: " << truncated_number << endl;
    return 0;
}
```

Note: The decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed during compilation. However, the decompiled code should still accurately represent the program logic.