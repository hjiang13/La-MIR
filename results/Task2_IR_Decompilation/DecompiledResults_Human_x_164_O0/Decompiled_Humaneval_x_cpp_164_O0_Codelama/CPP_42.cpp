Sure, here's the decompiled C++ source code for the provided IR code:

#include <iostream>
#include <vector>

using namespace std;

class std {
public:
    class vector {
    public:
        vector();
        vector(const vector& other);
        ~vector();

        size_t size() const;
        int& operator[](size_t index);

        void push_back(const int& value);
        void pop_back();

        class iterator {
        public:
            iterator(vector* vec, size_t index);
            ~iterator();

            int& operator*();
            iterator& operator++();
            iterator operator++(int);
            bool operator==(const iterator& other) const;
            bool operator!=(const iterator& other) const;

        private:
            vector* _vec;
            size_t _index;
        };

        iterator begin();
        iterator end();

    private:
        class _Vector_base {
        public:
            _Vector_base();
            _Vector_base(const _Vector_base& other);
            ~_Vector_base();

            size_t _Vector_impl::_M_impl_data::_M_start;
            size_t _Vector_impl::_M_impl_data::_M_finish;
            size_t _Vector_impl::_M_impl_data::_M_end_of_storage;
        };

        _Vector_base _M_impl;
    };
};

void incr_list(std::vector<int>& list) {
    for (int i = 0; i < list.size(); i++) {
        list[i]++;
    }
}

int main() {
    std::vector<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    incr_list(list);

    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << std::endl;
    }

    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should be functionally equivalent.