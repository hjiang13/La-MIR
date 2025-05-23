#include <vector>

int add_elements(std::vector<int> &vec, int size) {
    if (size > 0) {
        int *data = vec.data();
        size_t actual_size = static_cast<size_t>(size);
        int remaining_size = size < 8 ? 8 - size : 0;

        for (size_t i = 0; i < actual_size; i += 16, remaining_size -= 2) {
            size_t idx = i;
            std::vector<int> temp(4);
            std::vector<int> temp2(4);
            size_t check = remaining_size & 0x7FFFFFFFFFFFFFFE;
            
            for (size_t j = 0; j < 4; j++) {
                temp[j] = data[idx + j] + 99;
                temp2[j] = data[idx + 4 + j] + 99;
            }

            for (size_t j = 0; j < 4; j++) {
                temp[j] += temp2[j];
            }

            for (size_t j = 0; j < 4; j++) {
                data[idx + j] = temp[j];
                data[idx + 4 + j] = temp2[j];
            }
        }

        int result = 0;
        for (size_t i = 0; i < actual_size; i++) {
            int current = data[i] + 99;
            if (current < 199) {
                result += data[i];
            }
        }

        return result;
    }

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add_elements({1,-2,-3,41,57,76,87,88,99}, 3) == -4);
    assert (add_elements({111,121,3,4000,5,6}, 2) == 0);
    assert (add_elements({11,21,3,90,5,6,7,8,9}, 4) == 125);
    assert (add_elements({111,21,3,4000,5,6,7,8,9}, 4) == 24);
    assert (add_elements({1}, 1) == 1);
}
