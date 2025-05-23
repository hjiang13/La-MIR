Here is the equivalent C source code for the provided LLVM IR:
```c
#include <stdbool.h>
#include <string.h>

bool prime_length(const char *str) {
    int len = strlen(str);
    if (len < 2) {
        return false;
    }
    int i = 2;
    while (i * i <= len) {
        if (len % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}
```
Note that I've removed the unnecessary parts of the IR code, such as the metadata and the `std::__cxx11::basic_string` class, and translated the IR code into equivalent C code. Let me know if you need any further assistance!
#undef NDEBUG
#include<assert.h>
int main(){
    assert (prime_length("Hello") == true);
    assert (prime_length("abcdcba") == true);
    assert (prime_length("kittens") == true);
    assert (prime_length("orange") == false);
    assert (prime_length("wow") == true);
    assert (prime_length("world") == true);
    assert (prime_length("MadaM") == true);
    assert (prime_length("Wow") == true);
    assert (prime_length("") == false);
    assert (prime_length("HI") == true);
    assert (prime_length("go") == true);
    assert (prime_length("gogo") == false);
    assert (prime_length("aaaaaaaaaaaaaaa") == false);
    assert (prime_length("Madam") == true);
    assert (prime_length("M") == false);
    assert (prime_length("0") == false);
}
