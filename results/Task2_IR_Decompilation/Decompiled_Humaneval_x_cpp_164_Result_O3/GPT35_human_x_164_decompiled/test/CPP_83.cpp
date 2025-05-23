```c
#include <iostream>
#include <vector>

int starts_one_endsi(int arg) {
    if (arg < 1) {
        return 0;
    }
    if (arg == 1) {
        return 0;
    }
    if (arg > 2) {
        int temp = arg - 2;
        int temp2 = (temp & -8) | 2;
        int temp3 = (temp >> 3) + 1;
        int temp4 = temp3 & 7;
        if (temp < 56) {
            std::vector<int> vec1 = {18, 18, 18, 18};
            std::vector<int> vec2 = {1, 1, 1, 1};
            int temp5 = (temp3 & 1073741816);
            while (temp5 != 0) {
                for (int i = 0; i < 4; i++) {
                    vec1[i] *= 100000000;
                    vec2[i] *= 100000000;
                }
                temp5 -= 8;
            }
            temp3 = temp5;
        }
        int temp6 = temp4 == 0 ? 10 : 1;
        int temp7 = temp4 == 0 ? 10 : 1;
        while (temp4 != 0) {
            for (int i = 0; i < 4; i++) {
                vec1[i] *= temp6;
                vec2[i] *= temp7;
            }
            temp4--;
        }
        int result = 1;
        for (int i = 0; i < 4; i++) {
            result *= vec1[i] * vec2[i];
        }
        if (temp == (temp & -8)) {
            return 0;
        }
        return result;
    }
    int temp8 = 2;
    int temp9 = 18;
    while (true) {
        int temp10 = temp9 * 10;
        int temp11 = temp8 * 10;
        if (temp11 == arg) {
            return temp9;
        }
        temp8++;
        temp9 = temp10;
    }
}

int main() {
    int arg = 10; // Input argument value
    int result = starts_one_endsi(arg);
    std::cout << result << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (starts_one_ends(1) == 1);
    assert (starts_one_ends(2) == 18);
    assert (starts_one_ends(3) == 180);
    assert (starts_one_ends(4) == 1800);
    assert (starts_one_ends(5) == 18000);
}
