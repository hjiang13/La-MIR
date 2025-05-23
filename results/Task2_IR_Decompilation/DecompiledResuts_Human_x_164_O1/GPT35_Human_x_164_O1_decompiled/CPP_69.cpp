```cpp
#include <vector>

int search(std::vector<int> *v) {
    std::vector<int> temp;
    int result = -1;

    if (v->begin() == v->end()) {
        return result;
    }

    for (auto it = v->begin(); it != v->end(); ++it) {
        int val = *it;
        if (val > result) {
            result = val;
        }
    }

    return result;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int max = search(&vec);
    return 0;
}
```