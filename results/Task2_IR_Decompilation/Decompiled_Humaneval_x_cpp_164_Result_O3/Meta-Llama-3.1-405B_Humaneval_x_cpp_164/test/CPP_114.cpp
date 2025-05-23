long long minSubArraySum(std::vector<long long>& a) {
  long long* data = a.data();
  long long size = a.size();
  if (size <= 1) {
    return data[0];
  }
  long long min = data[0];
  long long current = data[0];
  for (long long i = 1; i < size; i++) {
    if (current < 0) {
      current = 0;
    }
    current += data[i];
    if (current < min) {
      min = current;
    }
  }
  return min;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (minSubArraySum({2, 3, 4, 1, 2, 4}) == 1);
    assert (minSubArraySum({-1, -2, -3}) == -6);
    assert (minSubArraySum({-1, -2, -3, 2, -10}) == -14);
    assert (minSubArraySum({-9999999999999999}) == -9999999999999999);
    assert (minSubArraySum({0, 10, 20, 1000000}) == 0);
    assert (minSubArraySum({-1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({100, -1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({10, 11, 13, 8, 3, 4}) == 3);
    assert (minSubArraySum({100, -33, 32, -1, 0, -2}) == -33);
    assert (minSubArraySum({-10}) == -10);
    assert (minSubArraySum({7}) == 7);
    assert (minSubArraySum({1, -1}) == -1);
}
