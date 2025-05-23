int largest_prime_factor(int n) {
    if (n < 4) {
        return n;
    }

    int i = 2;
    while (1) {
        if (n % i == 0 && n > i) {
            int j = n / i;
            while (j % i == 0 && j > i) {
                j /= i;
            }
            n = j;
            i++;
            if (i * i > n) {
                return n;
            }
        } else {
            i++;
            if (i * i > n) {
                return n;
            }
        }
    }
}
