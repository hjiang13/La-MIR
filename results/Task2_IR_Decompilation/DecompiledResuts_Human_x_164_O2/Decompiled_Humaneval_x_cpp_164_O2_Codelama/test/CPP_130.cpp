#include <iostream>
#include <vector>

using namespace std;

class vector {
private:
    struct _Vector_base {
        struct _Vector_impl {
            int* _M_start;
            int* _M_finish;
            int* _M_end_of_storage;
        } _M_impl;
    } _M_base;

public:
    vector() {
        _M_base._M_impl._M_start = nullptr;
        _M_base._M_impl._M_finish = nullptr;
        _M_base._M_impl._M_end_of_storage = nullptr;
    }

    vector(int size) {
        _M_base._M_impl._M_start = (int*)malloc(size * sizeof(int));
        _M_base._M_impl._M_finish = _M_base._M_impl._M_start;
        _M_base._M_impl._M_end_of_storage = _M_base._M_impl._M_start + size;
    }

    ~vector() {
        if (_M_base._M_impl._M_start != nullptr) {
            free(_M_base._M_impl._M_start);
        }
    }

    int size() {
        return _M_base._M_impl._M_finish - _M_base._M_impl._M_start;
    }

    int capacity() {
        return _M_base._M_impl._M_end_of_storage - _M_base._M_impl._M_start;
    }

    int* data() {
        return _M_base._M_impl._M_start;
    }

    void push_back(int value) {
        if (_M_base._M_impl._M_finish == _M_base._M_impl._M_end_of_storage) {
            int* new_start = (int*)malloc(2 * capacity() * sizeof(int));
            int* new_finish = new_start;
            int* new_end_of_storage = new_start + 2 * capacity();
            for (int* i = _M_base._M_impl._M_start; i != _M_base._M_impl._M_finish; ++i) {
                *new_finish++ = *i;
            }
            free(_M_base._M_impl._M_start);
            _M_base._M_impl._M_start = new_start;
            _M_base._M_impl._M_finish = new_finish;
            _M_base._M_impl._M_end_of_storage = new_end_of_storage;
        }
        *_M_base._M_impl._M_finish++ = value;
    }

    void pop_back() {
        if (_M_base._M_impl._M_finish != _M_base._M_impl._M_start) {
            --_M_base._M_impl._M_finish;
        }
    }

    int& operator[](int index) {
        return _M_base._M_impl._M_start[index];
    }

    int operator[](int index) const {
        return _M_base._M_impl._M_start[index];
    }

    void clear() {
        _M_base._M_impl._M_finish = _M_base._M_impl._M_start;
    }

    void resize(int size) {
        if (size > capacity()) {
            int* new_start = (int*)malloc(size * sizeof(int));
            int* new_finish = new_start;
            int* new_end_of_storage = new_start + size;
            for (int* i = _M_base._M_impl._M_start; i != _M_base._M_impl._M_finish; ++i) {
                *new_finish++ = *i;
            }
            free(_M_base._M_impl._M_start);
            _M_base._M_impl._M_start = new_start;
            _M_base._M_impl._M_finish = new_finish;
            _M_base._M_impl._M_end_of_storage = new_end_of_storage;
        } else {
            _M_base._M_impl._M_finish = _M_base._M_impl._M_start + size;
        }
    }

    void reserve(int size) {
        if (size > capacity()) {
            int* new_start = (int*)malloc(size * sizeof(int));
            int* new_finish = new_start;
            int* new_end_of_storage = new_start + size;
            for (int* i = _M_base._M_impl._M_start; i != _M_base._M_impl._M_finish; ++i) {
                *new_finish++ = *i;
            }
            free(_M_base._M_impl._M_start);
            _M_base._M_impl._M_start = new_start;
            _M_base._M_impl._M_finish = new_finish;
            _M_base._M_impl._M_end_of_storage = new_end_of_storage;
        }
    }

    void assign(int size, int value) {
        resize(size);
        for (int* i = _M_base._M_impl._M_start; i != _M_base._M_impl._M_finish; ++i) {
            *i = value;
        }
    }

    void insert(int index, int value) {
        if (index < 0 || index > size()) {
            return;
        }
        if (size() == capacity()) {
            int* new_start = (int*)malloc(2 * capacity() * sizeof(int));
            int* new_finish = new_start;
            int* new_end_of_storage = new_start + 2 * capacity();
            for (int* i = _M_base._M_impl._M_start; i != _M_base._M_impl._M_finish; ++i) {
                *new_finish++ = *i;
            }
            free(_M_base._M_impl._M_start);
            _M_base._M_impl._M_start = new_start;
            _M_base._M_impl._M_finish = new_finish;
            _M_base._M_impl._M_end_of_storage = new_end_of_storage;
        }
        for (int* i = _M_base._M_impl._M_finish; i != _M_base._M_impl._M_start + index; --i) {
            *i = *(i - 1);
        }
        *(_M_base._M_impl._M_start + index) = value;
        ++_M_base._M_impl._M_finish;
    }

    void erase(int index) {
        if (index < 0 || index >= size()) {
            return;
        }
        for (int* i = _M_base._M_impl._M_start + index; i != _M_base._M_impl._M_finish - 1; ++i) {
            *i = *(i + 1);
        }
        --_M_base._M_impl._M_finish;
    }

    void swap(vector& other) {
        std::swap(_M_base._M_impl._M_start, other._M_base._M_impl._M_start);
        std::swap(_M_base._M_impl._M_finish, other._M_base._M_impl._M_finish);
        std::swap(_M_base._M_impl._M_end_of_storage, other._M_base._M_impl._M_end_of_storage);
    }
};

int main() {
    vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    v.insert(1, 4);
    v.erase(1);
    v.clear();
    v.resize(10);
    v.reserve(20);
    v.assign(10, 5);
    vector v2;
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    v2.push_back(9);
    v2.push_back(10);
    v.swap(v2);
    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(tri(3) , {1, 3, 2, 8}));
    assert (issame(tri(4) , {1, 3, 2, 8, 3}));
    assert (issame(tri(5) , {1, 3, 2, 8, 3, 15}));
    assert (issame(tri(6) , {1, 3, 2, 8, 3, 15, 4}));
    assert (issame(tri(7) , {1, 3, 2, 8, 3, 15, 4, 24}));
    assert (issame(tri(8) , {1, 3, 2, 8, 3, 15, 4, 24, 5}));
    assert (issame(tri(9) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35}));
    assert (issame(tri(20) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35, 6, 48, 7, 63, 8, 80, 9, 99, 10, 120, 11}));
    assert (issame(tri(0) , {1}));
    assert (issame(tri(1) , {1, 3}));
}
