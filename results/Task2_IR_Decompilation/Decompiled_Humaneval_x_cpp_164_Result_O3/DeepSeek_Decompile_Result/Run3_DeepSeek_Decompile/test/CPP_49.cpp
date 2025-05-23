#include <cstdint>

using namespace std;

int modp(int a, int b) {
    if (a <= 0)
        return 1;
    
    int c = a - 1;
    int d = a & 3;
    
    if (c < 3)
        goto end;
    
    int e = a & -4;
    int f = 1;
    int g = e;
    
    while (true) {
        f <<= 1;
        f = (f & b) ? (f - b) : f;
        int h = (f << 1) & b;
        if (h)
            f = (h - b);
        int i = (f << 1) & b;
        if (i)
            f = (i - b);
        int j = (f << 1) & b;
        if (j)
            f = (j - b);
        int k = (f << 1) & b;
        if (k)
            f = (k - b);
        g += e;
        if (g == 0)
            break;
    }
    
end:
    if (d == 0)
        return 1;
    
    while (true) {
        int l = f;
        f = (f << 1) & b;
        f = (f ? f - b : f);
        if (f == 0)
            break;
    }
    
    return f;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (modp(3, 5) == 3);
    assert (modp(1101, 101) == 2);
    assert (modp(0, 101) == 1);
    assert (modp(3, 11) == 8);
    assert (modp(100, 101) == 1);
    assert (modp(30, 5) == 4);
    assert (modp(31, 5) == 3);
}
