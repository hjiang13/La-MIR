int greatest_common_divisor(int a, int b) {
    while (1) {
        int temp = a;
        a = b;
        b = temp % b;
        if (b == 0)
            return a;
    }
}
