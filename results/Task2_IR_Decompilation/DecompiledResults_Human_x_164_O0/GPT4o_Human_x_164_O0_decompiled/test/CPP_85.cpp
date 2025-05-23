#include <vector>

int add(std::vector<int>& vec) {
    int sum = 0;
    int index = 0;

    while (true) {
        if (index >= vec.size()) {
            break;
        }
        int value = vec[index];
        if (value % 2 == 0) {
            sum += value;
        }
        index++;
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
