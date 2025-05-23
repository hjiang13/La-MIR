int is_multiply_prime(int n) {
  if (n < 4) {
    int count = 0;
    return count == 2;
  } else {
    int i = 2;
    int count = 0;
    int temp = n;
    while (1) {
      if (temp % i == 0 && temp > i) {
        temp /= i;
        count++;
        while (temp % i == 0 && temp > i) {
          temp /= i;
          count++;
        }
      }
      i++;
      if (i * i > temp) {
        if (count == 2) {
          return 1;
        } else {
          return 0;
        }
      }
    }
  }
}
