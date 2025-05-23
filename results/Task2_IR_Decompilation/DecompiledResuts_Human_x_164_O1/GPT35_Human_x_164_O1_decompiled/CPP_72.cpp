```cpp
#include <vector>

bool will_it_fly(std::vector<int> &vec, int val) {
    int* end_ptr = &vec[0] + vec.size();
    int* begin_ptr = &vec[0];
    long diff = end_ptr - begin_ptr;
    long max_iterations = diff > 0 ? diff : 1;

    for (long i = 0; i < max_iterations; i++) {
        int a = vec[i];
        int b = vec[(i + val) % vec.size()];
        if (a != b) {
            return false;
        }
    }

    return true;
}
```