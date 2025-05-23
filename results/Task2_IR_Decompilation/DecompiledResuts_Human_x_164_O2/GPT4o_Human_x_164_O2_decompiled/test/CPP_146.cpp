#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>

int specialFilter(std::vector<int>& vec) {
    std::string str;
    int result = 0;
    
    int* first = vec.data();
    int* second = (int*)(vec.data() + vec.size());
    
    if (first == second) {
        return 0;
    }
    
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > 10) {
            snprintf((char*)str.c_str(), str.size(), "%d", vec[i]);
            if (str[str.size() - 1] % 2 == 1) {
                result++;
            }
        }
    }
    
    return result;
}

extern "C" {
    void vsnprintf(char* buffer, size_t count, const char* format, ...) {
        va_list args;
        va_start(args, format);
        vsnprintf(buffer, count, format, args);
        va_end(args);
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (specialFilter({5, -2, 1, -5}) == 0  );
    assert (specialFilter({15, -73, 14, -15}) == 1);
    assert (specialFilter({33, -2, -3, 45, 21, 109}) == 2);
    assert (specialFilter({43, -12, 93, 125, 121, 109}) == 4);
    assert (specialFilter({71, -2, -33, 75, 21, 19}) == 3);
    assert (specialFilter({1}) == 0              );
    assert (specialFilter({}) == 0                   );
}
