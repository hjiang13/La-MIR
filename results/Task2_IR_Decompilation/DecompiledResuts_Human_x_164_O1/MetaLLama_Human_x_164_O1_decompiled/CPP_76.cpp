#include <stdio.h>
#include <stdbool.h>

bool is_simple_power(int a, int b) {
    if (a > 0) {
        if (a > 1) {
            int i = 0;
            int x = 1;
            do {
                x *= b;
                i++;
                if (x <= a && i < 99) {
                    continue;
                } else {
                    return x == a;
                }
            } while (x != a);
        }
        return true;
    }
    return false;
}
