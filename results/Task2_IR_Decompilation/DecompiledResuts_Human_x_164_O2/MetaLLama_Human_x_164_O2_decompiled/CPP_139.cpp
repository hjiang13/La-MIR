long long special_factorial(int n) {
    if (n < 1) {
        return 1;
    }
    long long result = 1;
    long long i = (long long)n + 1;
    long long j = i - 1;
    long long k = i - 2;
    if (k < 7) {
        long long temp1 = 1;
        long long temp2 = 1;
        long long temp3 = 1;
        long long temp4 = (long long)(i - 1) & 7;
        while (temp4 != 0) {
            temp3 *= temp1;
            temp2 *= temp3;
            temp1 += 1;
            temp4 -= 1;
        }
        result = temp2;
    } else {
        long long temp1 = 1;
        long long temp2 = 1;
        long long temp3 = 1;
        long long temp4 = (long long)(i - 1) & -8;
        while (temp4 != 0) {
            temp3 *= temp1;
            temp2 *= temp3;
            temp3 *= temp1 + 1;
            temp2 *= temp3;
            temp3 *= temp1 + 2;
            temp2 *= temp3;
            temp3 *= temp1 + 3;
            temp2 *= temp3;
            temp3 *= temp1 + 4;
            temp2 *= temp3;
            temp3 *= temp1 + 5;
            temp2 *= temp3;
            temp3 *= temp1 + 6;
            temp2 *= temp3;
            temp3 *= temp1 + 7;
            temp2 *= temp3;
            temp1 += 8;
            temp4 -= 8;
        }
        result = temp2;
    }
    return result;
}
