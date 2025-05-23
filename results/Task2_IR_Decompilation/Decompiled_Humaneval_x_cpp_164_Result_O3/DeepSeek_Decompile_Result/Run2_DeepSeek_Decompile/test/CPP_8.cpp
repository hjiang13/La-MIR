#include <vector>
#include <immintrin.h>  // For SIMD operations

using namespace std;

vector<int> sum_product(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    if (a.empty()) {
        return result;
    }

    int sum = 0;
    int product = 1;
    size_t n = a.size();

    // Vectorized part (handles chunks of 4 elements)
    size_t vec_size = (n / 4) * 4;
    for (size_t i = 0; i < vec_size; i += 4) {
        __m128i a_vec = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&a[i]));
        __m128i b_vec = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&b[i]));

        __m128i product_vec = _mm_mul_epi32(a_vec, b_vec);
        __m128i sum_vec = _mm_add_epi32(a_vec, b_vec);

        int* product_ptr = reinterpret_cast<int>(&product_vec);
        int* sum_ptr = reinterpret_cast<int>(&sum_vec);

        sum += sum_ptr[0] + sum_ptr[1] + sum_ptr[2] + sum_ptr[3];
        product *= product_ptr[0] * product_ptr[1] * product_ptr[2] * product_ptr[3];
    }

    // Remainder part (handles remaining elements)
    for (size_t i = vec_size; i < n; ++i) {
        sum += a[i] + b[i];
        product *= a[i] * b[i];
    }

    result.push_back(sum);
    result.push_back(product);

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


