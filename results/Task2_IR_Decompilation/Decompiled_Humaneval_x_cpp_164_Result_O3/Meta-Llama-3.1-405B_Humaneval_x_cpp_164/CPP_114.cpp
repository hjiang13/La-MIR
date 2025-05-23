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
