Sure, here's the decompiled C++ source code for the provided IR code:

#include<stdio.h>
#include<string>
using namespace std;

class vector {
public:
    vector(int size, int value) {
        _Vector_impl_data = new int[size];
        for (int i = 0; i < size; i++) {
            _Vector_impl_data[i] = value;
        }
    }

    ~vector() {
        delete[] _Vector_impl_data;
    }

    int& operator[](int index) {
        return _Vector_impl_data[index];
    }

private:
    int* _Vector_impl_data;
};

void eati(vector& vec, int a, int b, int c) {
    int size = c - b;
    if (size < 0) {
        return;
    }

    int* data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = a + i;
    }

    vec[0] = data;
    vec[1] = size;
    vec[2] = data;
}

int main() {
    vector vec(3, 0);
    eati(vec, 1, 2, 3);
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.