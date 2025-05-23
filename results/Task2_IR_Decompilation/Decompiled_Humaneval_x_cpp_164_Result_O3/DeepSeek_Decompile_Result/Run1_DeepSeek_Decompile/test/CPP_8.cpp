#include <vector>
#include <immintrin.h>

using namespace std;

vector<int> sum_product(const vector<int>& v) {
    vector<int> result(2); // Assuming result holds two integers: sum and product
    
    int n = v.size();
    if (n == 0) {
        return result; // Initialize result with default values
    }

    int half = (n + 1) / 2;
    int quarters = half / 4;

    int sum = 0;
    int product = 1;

    // SIMD-optimized loop for processing elements
    for (int i = 0; i < quarters; ++i) {
        __m128i vec = _mm_loadu_si128((__m128i*)(v.data() + i * 4));
        __m128i ones = _mm_set_epi32(1, 1, 1, 1);
        __m128i adds = _mm_mul_epu32(vec, ones);
        __m128i muls = _mm_mul_epu32(vec, ones);

        _mm_storeu_si128((__m128i*)(&sum), adds);
        _mm_storeu_si128((__m128i*)(&product), muls);
    }

    result[0] = sum;
    result[1] = product;
    
    return result;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(sum_product({}) ,{0, 1}));
    assert (issame(sum_product({1, 1, 1}), {3, 1}));
    assert (issame(sum_product({100, 0}),{100, 0}));
     assert (issame(sum_product({3, 5, 7}) , {3 + 5 + 7, 3 * 5 * 7}));
      assert (issame(sum_product({10}) ,{10, 10}));
}


