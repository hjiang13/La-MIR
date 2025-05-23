int largest_prime_factor(int n) {
    if (n < 4) {
        return n;
    }

    int i = 2;
    int num = n;

    while (1) {
        if ((num % i) == 0 && num > i) {
            while ((num / i) % i == 0 && (num / i) > i) {
                num /= i;
            }
        }

        if (i * i > num) {
            return num;
        }

        i++;
    }

    return 0;
}
