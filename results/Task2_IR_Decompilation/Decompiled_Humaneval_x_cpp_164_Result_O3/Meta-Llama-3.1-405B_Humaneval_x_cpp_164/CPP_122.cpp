#include <stdio.h>
#include <stdint.h>

int add_elements(int* data, int size) {
    int result = 0;
    if (size > 0) {
        int i = 0;
        if (size >= 8) {
            int j = size & 4294967288;
            int k = (j - 8) >> 3;
            int l = k + 1;
            if ((l & 1) == 0) {
                int m = l & 4611686018427387902;
                int n = 0;
                int o = 0;
                int p = 0;
                do {
                    int* q = data + n;
                    __m128i r = _mm_loadu_si128((__m128i*)q);
                    __m128i s = _mm_loadu_si128((__m128i*)(q + 4));
                    __m128i t = _mm_add_epi32(r, _mm_set1_epi32(99));
                    __m128i u = _mm_add_epi32(s, _mm_set1_epi32(99));
                    __m128i v = _mm_cmplt_epi32(t, _mm_set1_epi32(199));
                    __m128i w = _mm_cmplt_epi32(u, _mm_set1_epi32(199));
                    __m128i x = _mm_blendv_epi8(_mm_setzero_si128(), r, v);
                    __m128i y = _mm_blendv_epi8(_mm_setzero_si128(), s, w);
                    o = _mm_add_epi32(o, x);
                    p = _mm_add_epi32(p, y);
                    n += 16;
                    m -= 2;
                } while (m != 0);
                result = _mm_extract_epi32(_mm_add_epi32(o, p), 0) + _mm_extract_epi32(_mm_add_epi32(o, p), 1) + _mm_extract_epi32(_mm_add_epi32(o, p), 2) + _mm_extract_epi32(_mm_add_epi32(o, p), 3);
                if (j != size) {
                    int z = size - j;
                    int* aa = data + j;
                    int bb = 0;
                    do {
                        int cc = *aa;
                        if (cc + 99 < 199) {
                            bb += cc;
                        }
                        aa++;
                        z--;
                    } while (z != 0);
                    result += bb;
                }
            } else {
                int dd = data[size - 1];
                if (dd + 99 < 199) {
                    result += dd;
                }
            }
        } else {
            int ee = 0;
            do {
                int ff = data[ee];
                if (ff + 99 < 199) {
                    result += ff;
                }
                ee++;
            } while (ee != size);
        }
    }
    return result;
}
