#include <string>
#include <vector>

void intersection(std::__cxx11::basic_string* s, std::vector* v1, std::vector* v2) {
    int* data1 = v1->data()->data();
    int* data2 = v2->data()->data();
    int size1 = v1->size();
    int size2 = v2->size();
    
    int minSize = size1 < size2 ? size1 : size2;
    
    for (int i = 0; i < minSize; i++) {
        if (data1[i] == data2[i]) {
            s->push_back(data1[i]);
        }
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
