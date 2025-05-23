```cpp
#include <vector>
#include <cstdlib>
#include <cstring>

class VectorWrapper {
public:
    std::vector<int*> data;
    std::vector<int*> ptrs;

    VectorWrapper() {
        data.resize(1);
        ptrs.resize(1);
    }

    ~VectorWrapper() {
        for (auto ptr : data) {
            if (ptr) {
                free(ptr);
            }
        }
    }

    void realloc_insert(size_t index) {
        if (index >= data.size()) {
            throw std::length_error("vector::_M_realloc_insert");
        }
        if (ptrs.size() <= index) {
            ptrs.resize(index + 1);
        }
        ptrs[index] = data[index];
    }
};

int search(VectorWrapper* vec) {
    int result = -1;
    for (size_t i = 0; i < vec->data.size(); ++i) {
        if (vec->data[i] == nullptr) {
            continue;
        }
        result = i;
        break;
    }
    return result;
}

int main() {
    VectorWrapper* vecWrapper = new VectorWrapper();
    vecWrapper->data[0] = (int*)malloc(sizeof(int) * 10);
    vecWrapper->data[1] = (int*)malloc(sizeof(int) * 10);
    
    // Example usage
    int result = search(vecWrapper);
    
    // Clean up
    delete vecWrapper;
    return 0;
}
```