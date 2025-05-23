```cpp
#include <string>
#include <cstring>

int hex_key(std::string key) {
    std::__cxx11::basic_string<char>::_Alloc_hider hider;
    hider = key.data();
    
    unsigned char str[7] = {0x23, 0x57, 0xBD, 0x00, 0x00, 0x00, 0x00};
    
    int key_size = key.size();
    if (key_size == 0) {
        return 0;
    } else {
        for (int i = 0; i < key_size; i++) {
            if (hider[i] != str[i]) {
                return 1;
            }
        }
    }
    
    return 0;
}
```