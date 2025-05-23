#include <vector>
#include <stdexcept>
#include <cstring>

class Matrix {
public:
    std::vector<int*> data;
    Matrix() {}

    Matrix(const Matrix& other) {
        data.resize(other.data.size());
        for (size_t i = 0; i < other.data.size(); ++i) {
            data[i] = new int[3]; // Assuming each row has 3 columns
            std::memcpy(data[i], other.data[i], 3 * sizeof(int));
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            for (size_t i = 0; i < data.size(); ++i) {
                delete[] data[i];
            }
            data.clear();
            data.resize(other.data.size());
            for (size_t i = 0; i < other.data.size(); ++i) {
                data[i] = new int[3];
                std::memcpy(data[i], other.data[i], 3 * sizeof(int));
            }
        }
        return *this;
    }

    ~Matrix() {
        for (size_t i = 0; i < data.size(); ++i) {
            delete[] data[i];
        }
    }
};

int get_matrix_triples(int size) {
    if (size < 1) return -1;
    Matrix matrix;
    for (int i = 0; i < size; ++i) {
        int* row = new int[3]{0, 0, 0};
        matrix.data.push_back(row);
    }

    // hypothetical processing
    // ...

    return size; // Return the size for now
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (get_matrix_triples(5) == 1);
    assert (get_matrix_triples(6) == 4);
    assert (get_matrix_triples(10) == 36);
    assert (get_matrix_triples(100) == 53361);
}
