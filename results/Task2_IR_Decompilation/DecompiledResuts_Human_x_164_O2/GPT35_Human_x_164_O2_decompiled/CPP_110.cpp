```c
#include <string>
#include <vector>

void exchange(std::__cxx11::basic_string* result, std::vector* vec1, std::vector* vec2) {
    int* data1 = vec1->data();
    int* data2 = vec1->data();
    int size1 = vec1->size();
    int size2 = vec2->size();

    for (int i = 0; i < size1; i++) {
        data1[i] ^= 1;
    }

    for (int i = 0; i < size2; i++) {
        data2[i] ^= 1;
    }

    if (size1 > size2) {
        result->assign("YES", 3);
    } else {
        result->assign("\x02\x4E", 2);
    }
}
```