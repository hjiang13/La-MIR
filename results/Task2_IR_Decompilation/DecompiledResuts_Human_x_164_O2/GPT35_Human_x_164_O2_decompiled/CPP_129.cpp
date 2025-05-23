```c
#include <vector>

void minPath(std::vector<std::vector<int>>& v, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) {
                int val = v[i][j];
                if (j + 1 < n && v[i][j + 1] == 1) {
                    val = j + 1;
                }
                if (i + 1 < n && v[i + 1][j] == 1) {
                    val = i + 1;
                }
                if (j - 1 >= 0 && v[i][j - 1] == 1) {
                    val = j - 1;
                }
                if (i - 1 >= 0 && v[i - 1][j] == 1) {
                    val = i - 1;
                }
                v[i][j] = val;
            }
        }
    }
}
```