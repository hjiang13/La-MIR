#include <string>
#include <cstdarg>
#include <cstdio>

void solve(std::string &result, int count, ...) {
    std::string temp;
    va_list args;
    va_start(args, count);
    char buffer[32];
    vsnprintf(buffer, sizeof(buffer), "%d", count);
    temp.append(buffer);
    va_end(args);
    
    result = temp;
}

int main() {
    std::string output;
    solve(output, 5);
    printf("%s\n", output.c_str());
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
