#include <vector>

extern "C" int add(std::vector<int>* vec) {
    int* data = vec->data();
    int size = vec->size();
    
    if (size <= 1) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }

    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add({4, 88}) == 88);
    assert (add({4, 5, 6, 7, 2, 122}) == 122);
    assert (add({4, 0, 6, 7}) == 0);
    assert (add({4, 4, 6, 8}) == 12);
}
