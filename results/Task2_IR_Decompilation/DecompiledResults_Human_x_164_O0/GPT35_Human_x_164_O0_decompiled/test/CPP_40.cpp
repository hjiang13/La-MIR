Here is the decompiled C++ source code from the given LLVM IR code:

```cpp
#include <vector>

bool triples_sum_to_zero(std::vector<int>* vec) {
    bool result = false;
    int size1 = 0;
    int size2 = 0;
    int size3 = 0;

    size1 = 0;
    while (size1 < vec->size()) {
        size2 = size1 + 1;
        while (size2 < vec->size()) {
            size3 = size2 + 1;
            while (size3 < vec->size()) {
                if ((*vec)[size1] + (*vec)[size2] + (*vec)[size3] == 0) {
                    result = true;
                    return result;
                }
                size3++;
            }
            size2++;
        }
        size1++;
    }

    return result;
}

int main() {
    std::vector<int> numbers = {1, -2, 3, -4, 5};
    bool result = triples_sum_to_zero(&numbers);

    if (result) {
        printf("Triple exists where sum is zero\n");
    } else {
        printf("No such triple exists\n");
    }

    return 0;
}
```

You can run this C++ code directly to check if a triple of integers exists in the vector such that their sum is zero.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (triples_sum_to_zero({1, 3, 5, 0}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -1}) == false);
    assert (triples_sum_to_zero({1, 3, -2, 1}) == true);
    assert (triples_sum_to_zero({1, 2, 3, 7}) == false);
    assert (triples_sum_to_zero({1, 2, 5, 7}) == false);
    assert (triples_sum_to_zero({2, 4, -5, 3, 9, 7}) == true);
    assert (triples_sum_to_zero({1}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -100}) == false);
    assert (triples_sum_to_zero({100, 3, 5, -100}) == false);
}
