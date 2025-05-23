float mean_absolute_deviation(vector<float>* input) {
  float sum = 0.0f;
  for (int i = 0; i < input->size(); i++) {
    sum += abs(input->at(i) - input->at(0));
  }
  return sum / input->size();
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}