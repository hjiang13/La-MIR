Sure, here's the decompiled C++ source code for the provided IR code:

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class std::allocator {
public:
    allocator() {}
};

class std::vector {
public:
    vector() {}
};

class std::__cxx11::basic_string {
public:
    basic_string() {}
};

void _ZNSaIcEC1Ev(std::allocator *this) {}
void _ZNSaIcED1Ev(std::allocator *this) {}
void _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_(std::__cxx11::basic_string *this, const char *str, std::allocator *alloc) {}
void _ZSt3maxIiERKT_S2_S2_(int *this, int *a, int *b) {}
void _ZSt3minIiERKT_S2_S2_(int *this, int *a, int *b) {}

void _Z12intersectionB5cxx11St6vectorIiSaIiEES1_(std::__cxx11::basic_string *this, std::vector *v1, std::vector *v2) {
    int *max, *min, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    std::allocator *alloc;
    max = _ZSt3maxIiERKT_S2_S2_(v1->data, v2->data);
    min = _ZSt3minIiERKT_S2_S2_(v1->data, v2->data);
    i = min;
    j = max;
    k = max;
    l = min;
    m = max;
    n = min;
    o = max;
    p = min;
    q = max;
    r = min;
    s = max;
    t = min;
    u = max;
    v = min;
    w = max;
    x = min;
    y = max;
    z = min;
    if (i < j) {
        alloc = new std::allocator();
        _ZNSaIcEC1Ev(alloc);
        _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_(this, "NO", alloc);
        _ZNSaIcED1Ev(alloc);
    } else {
        alloc = new std::allocator();
        _ZNSaIcEC1Ev(alloc);
        _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_(this, "YES", alloc);
        _ZNSaIcED1Ev(alloc);
    }
}

int main() {
    std::vector v1, v2;
    std::__cxx11::basic_string str;
    _Z12intersectionB5cxx11St6vectorIiSaIiEES1_(&str, &v1, &v2);
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or modified during compilation. Additionally, the decompiled code may contain additional or different variable names, and may have a different structure or organization than the original source code.