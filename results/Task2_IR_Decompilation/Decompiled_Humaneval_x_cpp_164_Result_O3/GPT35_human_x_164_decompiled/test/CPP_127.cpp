```c
#include <iostream>
#include <vector>
#include <string>

void intersection(std::__cxx11::basic_string* result, std::vector<int>* vec1, std::vector<int>* vec2) {
    int* v1 = &((*vec1)[0].data()[0]);
    int* v2 = &((*vec2)[0].data()[0]);
    int size1 = *v1;
    int size2 = *v2;
    int minSize = (size1 < size2) ? size2 : size1;
    
    if (minSize < 2) {
        result->data()[2] = 20302;
        result->size() = 2;
        result->data()[2] = 0;
    } else if (minSize < 4) {
        result->data()[2] = 20302;
        result->size() = 2;
        result->data()[2] = 0;
    } else {
        memcpy(result->data(), "YES", 3);
        result->size() = 3;
        result->data()[3] = 0;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (intersection({1, 2}, {2, 3}) == "NO");
    assert (intersection({-1, 1}, {0, 4}) == "NO");
    assert (intersection({-3, -1}, {-5, 5}) == "YES");
    assert (intersection({-2, 2}, {-4, 0}) == "YES");
    assert (intersection({-11, 2}, {-1, -1}) == "NO");
    assert (intersection({1, 2}, {3, 5}) == "NO");
    assert (intersection({1, 2}, {1, 2}) == "NO");
    assert (intersection({-2, -2}, {-3, -2}) == "NO");
}
