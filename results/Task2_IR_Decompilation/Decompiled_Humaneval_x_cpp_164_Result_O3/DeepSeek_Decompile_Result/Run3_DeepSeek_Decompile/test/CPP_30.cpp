#include <vector>
#include <cstring>
#include <stdexcept>

using namespace std;

void get_positive(vector<float> &result, const vector<float> &source) {
    // Initialize the result vector's internal pointers to null
    memset(&result, 0, sizeof(result));

    const float* src_begin = source.data();
    const float* src_end = src_begin + source.size();

    float* dest_begin = nullptr;
    float* dest_end = nullptr;
    float* dest_cap = nullptr;

    size_t capacity = 0;

    for (const float* src_it = src_begin; src_it != src_end; ++src_it) {
        if (*src_it > 0.0f) {
            if (dest_begin == dest_end) {
                // Calculate the required capacity
                size_t needed_capacity = max(static_cast<size_t>(1), (dest_end - src_begin + 1) * 2);
                float* new_mem = static_cast<float*>(operator new(needed_capacity * sizeof(float)));

                if (dest_begin != nullptr) {
                    memcpy(new_mem, dest_begin, (dest_end - dest_begin) * sizeof(float));
                    operator delete(dest_begin, dest_begin - dest_cap);
                }

                dest_begin = new_mem;
                dest_end = dest_begin;
                dest_cap = dest_begin + needed_capacity;
            }

            *dest_end++ = *src_it;
        }
    }

    result.data() = dest_begin;
    result.size() = dest_end - dest_begin;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(get_positive({-1, -2, 4, 5, 6}) , {4, 5, 6} ));
    assert (issame(get_positive({5, 3, -5, 2, 3, 3, 9, 0, 123, 1, -10}) , {5, 3, 2, 3, 3, 9, 123, 1}));
     assert (issame(get_positive({-1, -2}) , {} ));
     assert (issame(get_positive({}) , {}));
}
