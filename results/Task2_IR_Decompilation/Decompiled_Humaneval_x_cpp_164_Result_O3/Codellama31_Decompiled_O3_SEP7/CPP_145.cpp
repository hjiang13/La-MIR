Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class vector {
public:
    vector(int size) {
        _M_impl._M_start = new int[size];
        _M_impl._M_finish = _M_impl._M_start;
        _M_impl._M_end_of_storage = _M_impl._M_start + size;
    }

    ~vector() {
        delete[] _M_impl._M_start;
    }

    int& operator[](int index) {
        return _M_impl._M_start[index];
    }

    int size() {
        return _M_impl._M_finish - _M_impl._M_start;
    }

    void push_back(int value) {
        if (_M_impl._M_finish == _M_impl._M_end_of_storage) {
            int* new_storage = new int[2 * size()];
            for (int i = 0; i < size(); i++) {
                new_storage[i] = _M_impl._M_start[i];
            }
            delete[] _M_impl._M_start;
            _M_impl._M_start = new_storage;
            _M_impl._M_finish = _M_impl._M_start + size();
            _M_impl._M_end_of_storage = _M_impl._M_start + 2 * size();
        }
        *_M_impl._M_finish = value;
        _M_impl._M_finish++;
    }

private:
    struct _Vector_impl {
        int* _M_start;
        int* _M_finish;
        int* _M_end_of_storage;
    } _M_impl;
};

void order_by_points(vector<int>& points) {
    int n = points.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (points[j] > points[j + 1]) {
                int temp = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<int> points;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int point;
        cin >> point;
        points.push_back(point);
    }
    order_by_points(points);
    for (int i = 0; i < n; i++) {
        cout << points[i] << " ";
    }
    cout << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways. However, the decompiled code should be functionally equivalent to the original source code.