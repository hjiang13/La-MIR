float mean_absolute_deviation(vector<float> input) {
    float sum = 0.0;
    float mean = 0.0;
    for (int i = 0; i < input.size(); i++) {
        sum += input[i];
    }
    mean = sum / input.size();
    sum = 0.0;
    for (int i = 0; i < input.size(); i++) {
        sum += abs(input[i] - mean);
    }
    return sum / input.size();
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}