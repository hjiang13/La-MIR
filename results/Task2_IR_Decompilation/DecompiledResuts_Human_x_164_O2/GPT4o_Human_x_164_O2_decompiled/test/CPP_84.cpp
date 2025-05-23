#include <iostream>
#include <string>
#include <cstdarg>

void solve(std::string& s, int n) {
    char buffer[3];
    snprintf(buffer, sizeof(buffer), "%d", n);
    
    if (s.empty()) {
        s.append(buffer);
    } else {
        std::string temp(s);
        if (temp.size() == 1) {
            s[0] = temp[0];
        } else {
            memcpy(&s[0], temp.data(), temp.size());
        }
    }
    
    s.push_back(0);
}

int main() {
    std::string result;
    solve(result, 42);
    std::cout << result << std::endl;
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
