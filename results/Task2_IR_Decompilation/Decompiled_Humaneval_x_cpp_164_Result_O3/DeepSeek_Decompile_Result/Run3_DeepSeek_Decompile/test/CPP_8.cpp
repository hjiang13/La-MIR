#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> sum_product(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) {
        return vector<int>();
    }

    size_t n = a.size();
    vector<int> result(1);

    if (n == 0) {
        return result;
    }

    size_t vec_size = (n / 4) * 4;
    size_t tail = n - vec_size;

    int sum = 0;

    // Vectorized loop for processing 4 elements at a time
    for (size_t i = 0; i < vec_size; i += 4) {
        // Load four elements from each vector
        int* a_ptr = &a[i];
        int* b_ptr = &b[i];

        // Compute products and sum
        int prod1 = a_ptr[0] * b_ptr[0];
        int prod2 = a_ptr[1] * b_ptr[1];
        int prod3 = a_ptr[2] * b_ptr[2];
        int prod4 = a_ptr[3] * b_ptr[3];

        sum += prod1 + prod2 + prod3 + prod4;
    }

    // Process remaining elements
    for (size_t i = vec_size; i < n; ++i) {
        sum += a[i] * b[i];
    }

    result[0] = sum;
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


