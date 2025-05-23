#include <vector>

int max_fill(std::vector<int>* vec, int val) {
    int size = vec->size();
    int sum = 0;

    for (int i = 0; i < size; i++) {
        std::vector<int> temp = (*vec)[i];
        int inner_size = temp.size();

        for (int j = 0; j < inner_size; j++) {
            sum += temp[j];
        }
    }

    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (max_fill({{0,0,1,0}, {0,1,0,0}, {1,1,1,1}}, 1) == 6);
    assert (max_fill({{0,0,1,1}, {0,0,0,0}, {1,1,1,1}, {0,1,1,1}}, 2) == 5);
    assert (max_fill({{0,0,0}, {0,0,0}}, 5) == 0);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 2) == 4);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 9) == 2);
}
