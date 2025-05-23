#include <immintrin.h>
#include <string>

using namespace std;

int digitSum(const string& s) {
    int sum = 0;
    size_t length = s.length();
    const char* chars = s.c_str();

    if (length == 0) {
        return 0;
    }

    // SIMD vectorized loop
    for (size_t i = 0; i <= length - 16; i += 16) {
        __m128i vec1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(chars + i));
        __m128i vec2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(chars + i + 8));

        __m128i mask = _mm_set1_epi8('0' - 1);
        __m128i ones = _mm_set1_epi8(1);

        __m128i filtered1 = _mm_max_epu8(_mm_sub_epi8(vec1, mask), ones);
        __m128i filtered2 = _mm_max_epu8(_mm_sub_epi8(vec2, mask), ones);

        int sum1 = _mm_reduce_add_ps(_mm_cvtepi8_ps(filtered1));
        int sum2 = _mm_reduce_add_ps(_mm_cvtepi8_ps(filtered2));

        sum += sum1 + sum2;
    }

    // Handle remaining characters
    size_t remainder = length % 16;
    for (size_t i = length - remainder; i < length; ++i) {
        if (isdigit(s[i])) {
            sum += s[i] - '0';
        }
    }

    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (digitSum("") == 0);
    assert (digitSum("abAB") == 131);
    assert (digitSum("abcCd") == 67);
    assert (digitSum("helloE") == 69);
    assert (digitSum("woArBld") == 131);
    assert (digitSum("aAaaaXa") == 153);
    assert (digitSum(" How are yOu?") == 151);
    assert (digitSum("You arE Very Smart") == 327);
}
