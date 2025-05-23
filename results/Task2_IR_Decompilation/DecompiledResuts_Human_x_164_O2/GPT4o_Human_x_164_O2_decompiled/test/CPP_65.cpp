#include <cstdarg>
#include <cstdint>
#include <cstring>
#include <string>

std::string circular_shift(std::string s, int start, int length) {
    std::string result;
    int s_size = s.size();
    if (length > s_size) return result;
    if (length <= 0) return result;

    result.resize(s_size);
    std::memcpy(&result[0], &s[start], length);
    result[length] = '\0';
    return result;
}

extern "C" void __to_xstring(std::string &s, int (*func)(char*, std::size_t, const char*, va_list), std::size_t size, const char *str, ...) {
    va_list args;
    va_start(args, str);
    int len = func(&s[0], size, str, args);
    va_end(args);
    
    s.resize(len);
    s[len] = '\0';
}

extern "C" void test() {
    std::string s = "Hello, World!";
    std::string shifted = circular_shift(s, 0, 5);
    __to_xstring(s, vsnprintf, 16, "%s", "Test");
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (circular_shift(100, 2) == "001");
    assert (circular_shift(12, 2) == "12");
    assert (circular_shift(97, 8) == "79");
    assert (circular_shift(12, 1) == "21");
    assert (circular_shift(11, 101) == "11");
}
