```cpp
#include <vector>
#include <new>
#include <cstdlib>

extern "C" void __gxx_personality_v0();

void eati(std::vector<int>& vec, int a, int b, int c) {
    if (c < b) {
        void* ptr = operator new(8);
        if (ptr) {
            int idx = c + a;
            int* data = reinterpret_cast<int*>(ptr);
            vec.push_back(idx);
            *(reinterpret_cast<int*>(ptr) + 1) = 0; // Placeholder for second element
            *(reinterpret_cast<int*>(ptr) + 2) = reinterpret_cast<int>(ptr); // Store pointer
        } else {
            // Handle allocation failure
            std::terminate();
        }
    } else {
        void* ptr = operator new(8);
        if (ptr) {
            int idx = b + a;
            int* data = reinterpret_cast<int*>(ptr);
            vec.push_back(idx);
            *(reinterpret_cast<int*>(ptr) + 1) = 0; // Placeholder for second element
            *(reinterpret_cast<int*>(ptr) + 2) = reinterpret_cast<int>(ptr); // Store pointer
        } else {
            // Handle allocation failure
            std::terminate();
        }
    }
}
```