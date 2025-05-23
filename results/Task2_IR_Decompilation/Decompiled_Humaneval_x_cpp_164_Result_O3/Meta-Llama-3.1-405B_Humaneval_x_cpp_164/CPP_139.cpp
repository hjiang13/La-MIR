long long special_factorial(int n) {
    if (n < 1) return 1;

    long long result = 1;
    if (n <= 7) {
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    long long temp1 = n + 1;
    long long temp2 = temp1 - 1;
    long long temp3 = temp1 - 2;

    temp3 &= 7;
    long long temp4 = temp2 < 7;

    if (temp4) {
        long long temp5 = 1;
        long long temp6 = 1;
        long long temp7 = 1;

        while (temp3 != 0) {
            temp7 *= temp5;
            temp6 *= temp7;
            temp5++;
            temp3--;
        }
        return temp6;
    }

    long long temp8 = temp1 - 8;
    long long temp9 = 1;
    long long temp10 = 1;
    long long temp11 = temp8;

    while (temp11 != 0) {
        temp10 *= temp9;
        temp9 *= temp10;
        temp9++;
        temp10 *= temp9;
        temp9++;
        temp10 *= temp9;
        temp9++;
        temp10 *= temp9;
        temp9++;
        temp10 *= temp9;
        temp9++;
        temp10 *= temp9;
        temp9++;
        temp10 *= temp9;
        temp9++;
        temp10 *= temp9;
        temp9++;
        temp11 -= 8;
    }

    while (temp3 != 0) {
        temp7 *= temp5;
        temp6 *= temp7;
        temp5++;
        temp3--;
    }

    return temp6;
}
