#include <vector>

int solutions(std::vector<int> *v) {
    int sum = 0;
    for (int i = 0; i < v->size(); i++) {
        if ((*v)[i] % 2 == 1) {
            sum += (*v)[i];
        }
    }
    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solutions({5, 8, 7, 1})    == 12);
    assert (solutions({3, 3, 3, 3, 3}) == 9);
    assert (solutions({30, 13, 24, 321}) == 0);
    assert (solutions({5, 9}) == 5);
    assert (solutions({2, 4, 8}) == 0);
    assert (solutions({30, 13, 23, 32}) == 23);
    assert (solutions({3, 13, 2, 9}) == 3);
}
