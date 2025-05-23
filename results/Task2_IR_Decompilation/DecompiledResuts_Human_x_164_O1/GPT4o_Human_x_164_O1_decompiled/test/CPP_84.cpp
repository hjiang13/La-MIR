#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <string>

void solve(std::string &result, int value) {
    std::string buffer;
    int length = snprintf(buffer.data(), 16, "%d", value);

    if (length > 0) {
        result = buffer;
    } else {
        result.clear();
    }
}

int main() {
    std::string output;
    int value = 42;
    solve(output, value);
    printf("Result: %s\n", output.c_str());
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solve(1000) == "1");
    assert (solve(150) == "110");
    assert (solve(147) == "1100");
    assert (solve(333) == "1001");
    assert (solve(963) == "10010");
}
