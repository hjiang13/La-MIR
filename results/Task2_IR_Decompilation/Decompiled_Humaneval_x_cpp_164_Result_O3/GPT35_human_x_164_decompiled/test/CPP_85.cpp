```c
#include <vector>

int add(std::vector<int> & vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
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
