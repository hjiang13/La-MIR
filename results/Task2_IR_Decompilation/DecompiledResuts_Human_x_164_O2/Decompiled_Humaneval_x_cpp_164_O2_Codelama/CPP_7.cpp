Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class vector {
public:
    vector();
    ~vector();
    void _M_realloc_insert(vector *this, vector *other, vector *other_end);

private:
    struct _Vector