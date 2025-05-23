#include <vector>

int solutions(std::vector<int> &vec) {
    int result = 0;
    int index = 0;

    while (true) {
        if (index * 2 < vec.size()) {
            int value = vec[index * 2];
            if (value % 2 == 1) {
                result += value;
            }
        } else {
            break;
        }
        
        index += 1;
    }

    return result;
}

int main() {
    std::vector<int> vec = { /* Initialize with values */ };
    int result = solutions(vec);
    return result;
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
