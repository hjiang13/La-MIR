#include <string>
#include <vector>

void exchange(std::__cxx11::basic_string* result, std::vector* vec1, std::vector* vec2) {
    int* data1 = vec1->data();
    int* data2 = vec1->data();
    int size1 = vec1->size();
    int size2 = vec2->size();

    for (int i = 0; i < size1; i++) {
        data1[i] ^= 1;
    }

    for (int i = 0; i < size2; i++) {
        data2[i] ^= 1;
    }

    if (size1 > size2) {
        result->assign("YES", 3);
    } else {
        result->assign("\x02\x4E", 2);
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (exchange({1, 2, 3, 4}, {1, 2, 3, 4}) == "YES");
    assert (exchange({1, 2, 3, 4}, {1, 5, 3, 4}) == "NO");
    assert (exchange({1, 2, 3, 4}, {2, 1, 4, 3}) == "YES" );
    assert (exchange({5, 7, 3}, {2, 6, 4}) == "YES");
    assert (exchange({5, 7, 3}, {2, 6, 3}) == "NO" );
    assert (exchange({3, 2, 6, 1, 8, 9}, {3, 5, 5, 1, 1, 1}) == "NO");
    assert (exchange({100, 200}, {200, 200}) == "YES");
}
