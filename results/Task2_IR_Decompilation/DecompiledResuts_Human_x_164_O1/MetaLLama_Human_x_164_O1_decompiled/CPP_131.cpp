#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digits(int n) {
    char buffer[16];
    sprintf(buffer, "%d", n);
    int result = 0;
    int sign = 1;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '-') {
            sign = -1;
        } else {
            result = result * 10 + (buffer[i] - '0');
        }
    }
    return sign * result;
}

int main() {
    // Note: The main function is not present in the provided IR code.
    // This is just a placeholder to make the code compilable.
    return 0;
}
