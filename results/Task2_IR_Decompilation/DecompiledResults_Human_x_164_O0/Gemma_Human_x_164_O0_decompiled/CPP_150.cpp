Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>

int x_or_y(int a, int b, int c) {
    int d;
    int e;
    int f;
    char g;
    int h;

    d = a;
    e = b;
    f = c;
    g = 1;

    if (d < 2) {
        g = 0;
    }

    h = 2;

    while (1) {
        int i = h * h;
        if (i > d) break;

        int j = d % h;
        if (j == 0) {
            g = 0;
        }

        h++;
    }

    if (g) {
        return e;
    } else {
        return f;
    }
}
```

Note that I've used the same variable names as in the IR code to maintain consistency. Also, I've assumed that the function returns an `int` value, as indicated by the IR code. Let me know if you have any further questions or if there's anything else I can help you with!