int is_prime(long long x) {
    if (x < 2) {
        return 0;
    }
    if (x < 4) {
        return 1;
    }
    long long i = 2;
    do {
        if (x % i == 0) {
            return 0;
        }
        i = i + 1;
        if (i * i > x) {
            break;
        }
    } while (1);
    return 1;
}
