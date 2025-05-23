```cpp
#include <string>
#include <cstring>
#include <cstdlib>

void encrypt(std::string &output, const std::string &input) {
    size_t inputLength = input.length();
    output.resize(inputLength);
    if (inputLength == 0) {
        return;
    }

    for (size_t i = 0; i < inputLength; ++i) {
        output[i] = (input[i] - 93 + 26) % 26 + 'a';
    }
    output[inputLength] = '\0';
}
```