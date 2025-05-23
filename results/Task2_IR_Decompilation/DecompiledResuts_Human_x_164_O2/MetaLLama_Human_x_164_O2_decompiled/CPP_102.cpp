int choose_num(int a, int b) {
    if (b < a) {
        return -1;
    } else if (b == a && b % 2 == 1) {
        return -1;
    } else {
        return (b % 2 == 1) + b;
    }
}
