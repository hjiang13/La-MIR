#include <vector>
#include <iostream>
#include <cmath>

int sum_squares(std::vector<float> &vec) {
    float *begin = &vec[0];
    float *end = &vec[vec.size()];

    int sum = 0;
    for (float *ptr = begin; ptr < end; ptr++) {
        float value = std::ceil(*ptr);
        float square = value * value;
        sum += static_cast<int>(square);
    }

    return sum;
}

int main() {
    std::vector<float> vec = {1.5, 2.3, 3.7, 4.2, 5.6};
    int result = sum_squares(vec);
    std::cout << "Sum of squares: " << result << std::endl;

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_squares({1,2,3})==14);
    assert (sum_squares({1.0,2,3})==14);
    assert (sum_squares({1,3,5,7})==84);
    assert (sum_squares({1.4,4.2,0})==29);
    assert (sum_squares({-2.4,1,1})==6);
    assert (sum_squares({100,1,15,2})==10230);
    assert (sum_squares({10000,10000})==200000000);
    assert (sum_squares({-1.4,4.6,6.3})==75);
    assert (sum_squares({-1.4,17.9,18.9,19.9})==1086);
    assert (sum_squares({0})==0);
    assert (sum_squares({-1})==1);
    assert (sum_squares({-1,1,0})==2);
}
