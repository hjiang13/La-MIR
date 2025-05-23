```c
#include <bits/stdc++.h>

using namespace std;

int digits(int n) {
    string s;
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", n);
    s = buffer;
    int sum = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            sum += (c - '0');
        }
    }
    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (digits(5) == 5);
    assert (digits(54) == 5);
    assert (digits(120) ==1);
    assert (digits(5014) == 5);
    assert (digits(98765) == 315);
    assert (digits(5576543) == 2625);
    assert (digits(2468) == 0);
}
