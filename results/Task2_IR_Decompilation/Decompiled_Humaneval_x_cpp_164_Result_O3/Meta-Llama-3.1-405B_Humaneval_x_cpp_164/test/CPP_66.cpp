#include <stdint.h>

int digitSum(const char* str, int64_t length) {
    int32_t sum = 0;
    if (length == 0) return sum;

    if (length < 8) {
        for (int64_t i = 0; i < length; i++) {
            char c = str[i];
            if (c >= 'A' && c <= 'Z') sum += c - 'A' + 1;
        }
        return sum;
    }

    int64_t alignedLength = length & ~7;
    int64_t remainder = length - alignedLength;

    for (int64_t i = 0; i < alignedLength; i += 16) {
        __m128i chunk1 = _mm_loadu_si128((__m128i*)&str[i]);
        __m128i chunk2 = _mm_loadu_si128((__m128i*)&str[i + 8]);

        chunk1 = _mm_sub_epi8(chunk1, _mm_set1_epi8('A' - 1));
        chunk2 = _mm_sub_epi8(chunk2, _mm_set1_epi8('A' - 1));

        __m128i mask1 = _mm_cmpgt_epi8(_mm_set1_epi8(25), chunk1);
        __m128i mask2 = _mm_cmpgt_epi8(_mm_set1_epi8(25), chunk2);

        chunk1 = _mm_and_si128(chunk1, mask1);
        chunk2 = _mm_and_si128(chunk2, mask2);

        sum += _mm_reduce_add_epi32(_mm_cvtepi8_epi32(chunk1));
        sum += _mm_reduce_add_epi32(_mm_cvtepi8_epi32(chunk2));
    }

    if (remainder) {
        for (int64_t i = alignedLength; i < length; i++) {
            char c = str[i];
            if (c >= 'A' && c <= 'Z') sum += c - 'A' + 1;
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
