bool is_prime(long long x) {
    if (x < 2) {
        return false;
    }
    if (x < 4) {
        return true;
    }
    long long i = 2;
    while (1) {
        long long rem = x % i;
        if (rem == 0) {
            return false;
        }
        long long i_squared = i * i;
        if (i_squared > x) {
            break;
        }
        i++;
    }
    return true;
}
