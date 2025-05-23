#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

extern "C" int __gxx_personality_v0(void);
extern "C" void* operator new(std::size_t size) noexcept { return malloc(size); }
extern "C" void operator delete(void* ptr) noexcept { free(ptr); }

int skjkasdkd(std::vector<int> vec) {
    std::string str1, str2;
    int count = 0;
    size_t vec_size = vec.size();

    if (vec_size == 0) {
        count = 0;
    } else {
        size_t n = (vec_size > 4) ? (vec_size >> 2) : 1;

        for (size_t i = 0; i < n; ++i) {
            if (vec[i] > count) {
                count = vec[i];
            }
        }
    }

    snprintf(&str1[0], str1.size(), "%d", count);

    if (str1 == str2) {
        return 0;
    }

    size_t len = str1.length();
    if (len == 0) {
        return 0;
    }

    if (len > 15) {
        str1.resize(len);
        str2 = str1;
    }

    return 0;
}

extern "C" void vsnprintf(char* buffer, std::size_t count, const char* format, ...) {
    va_list args;
    va_start(args, format);
    std::vsnprintf(buffer, count, format, args);
    va_end(args);
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (skjkasdkd({0,3,2,1,3,5,7,4,5,5,5,2,181,32,4,32,3,2,32,324,4,3}) == 10);
    assert (skjkasdkd({1,0,1,8,2,4597,2,1,3,40,1,2,1,2,4,2,5,1}) == 25);
    assert (skjkasdkd({1,3,1,32,5107,34,83278,109,163,23,2323,32,30,1,9,3}) == 13);
    assert (skjkasdkd({0,724,32,71,99,32,6,0,5,91,83,0,5,6}) == 11);
    assert (skjkasdkd({0,81,12,3,1,21}) == 3);
    assert (skjkasdkd({0,8,1,2,1,7}) == 7);
    assert (skjkasdkd({8191}) == 19);
    assert (skjkasdkd({8191, 123456, 127, 7}) == 19);
    assert (skjkasdkd({127, 97, 8192}) == 10);
}
