int modp(int a, int b) {
    if (a > 0) {
        if ((a & 3) == 0) {
            a = 1;
        } else {
            int c = a - 1;
            int d = a & 3;
            int e = 1;
            do {
                e = (e << 1) % b;
                d--;
            } while (d != 0);
            a = e;
        }
    } else {
        a = 1;
    }
    return a;
}
