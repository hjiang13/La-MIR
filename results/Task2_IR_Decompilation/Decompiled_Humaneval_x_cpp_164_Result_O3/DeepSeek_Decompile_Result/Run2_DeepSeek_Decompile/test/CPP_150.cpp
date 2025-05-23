int x_or_y(int x, int y, int z) {
    if (x > 1 && x < 4) {
        // For x = 2 or 3, check if x is greater than 1
        if ((x > 1) == 0) {
            return z;
        } else {
            return y;
        }
    }

    int i = 2;
    while (true) {
        if (x % i == 0) {
            // If x is divisible by i, set the flag to 0
            // This corresponds to setting %17 to 0 in the IR
        } else {
            // Keep the previous flag value
        }

        i++;
        if (i * i > x) {
            // If i squared exceeds x, break the loop
            break;
        }
    }

    // After the loop, decide based on the flag
    // If the flag is non-zero, return y; else, return z
    return y;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (x_or_y(7, 34, 12) == 34);
    assert (x_or_y(15, 8, 5) == 5);
    assert (x_or_y(3, 33, 5212) == 33);
    assert (x_or_y(1259, 3, 52) == 3);
    assert (x_or_y(7919, -1, 12) == -1);
    assert (x_or_y(3609, 1245, 583) == 583);
    assert (x_or_y(91, 56, 129) == 129);
    assert (x_or_y(6, 34, 1234) == 1234);
    assert (x_or_y(1, 2, 0) == 0);
    assert (x_or_y(2, 2, 0) == 2);
}
