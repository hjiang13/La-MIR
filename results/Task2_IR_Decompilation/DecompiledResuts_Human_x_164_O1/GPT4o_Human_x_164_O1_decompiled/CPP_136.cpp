```cpp
#include <vector>
#include <cstdlib>
#include <cstring>

void largest_smallest_integers(std::vector<int>* result, const std::vector<int>* input) {
    if (input->size() == 0) {
        result->clear();
        return;
    }

    int smallest = input->at(0);
    int largest = input->at(0);

    for (size_t i = 1; i < input->size(); ++i) {
        int current = input->at(i);
        if (current < smallest) {
            smallest = current;
        }
        if (current > largest) {
            largest = current;
        }
    }

    result->clear();
    result->resize(2);
    (*result)[0] = smallest;
    (*result)[1] = largest;
}
```