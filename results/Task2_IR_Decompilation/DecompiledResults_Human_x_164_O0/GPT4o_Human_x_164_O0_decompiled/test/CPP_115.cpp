#include <vector>

int max_fill(std::vector<int> &vec, int size) {
    int count = 0;
    int index = 0;
    int total = 0;

    while (index < vec.size()) {
        total += vec[index];
        count++;
        index++;
    }

    if (count > 0) {
        return total / count + 1;
    }
    return 0;
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
