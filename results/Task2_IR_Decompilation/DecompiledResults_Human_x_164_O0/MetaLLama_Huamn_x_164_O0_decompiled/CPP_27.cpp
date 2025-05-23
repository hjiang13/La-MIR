Based on the LLVM IR code provided, I will generate the equivalent C source code. Here it is:

```c
#include <string.h>
#include <stdio.h>

void filp_case(std::string* result, const std::string& input) {
    std::string temp;
    int len = input.length();
    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        } else if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
        temp += c;
    }
    *result = temp;
}

int main() {
    std::string input = "";
    std::string result;
    filp_case(&result, input);
    return 0;
}
```

Please note that this C code uses the `std::string` class which is a C++ feature. If you need pure C code, you would need to replace `std::string` with a C equivalent, such as a character array or a struct to represent a string. 

Also, the generated C code might not be perfect and may require some manual adjustments to work as expected, because LLVM IR to C conversion is not always a straightforward process.