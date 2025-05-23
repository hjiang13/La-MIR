#include <vector>
#include <cstring> // for memset

using namespace std;

void derivative(vector<float>& result, const vector<float>& input) {
    // Calculate the size needed for the result vector
    size_t size = input.size();
    
    // Ensure the result vector is properly sized and initialized
    if (result.capacity() < size) {
        result.reserve(size);
    }
    memset(&result[0], 0, sizeof(float) * size);
    
    // Handle cases where the input vector is too small
    if (size <= 1) {
        result.resize(0);
        return;
    }
    
    // Resize the result vector if necessary
    result.resize(size - 1);
    
    // Compute the derivative for each element
    for (size_t i = 1; i < size; ++i) {
        result[i - 1] = input[i] - input[i - 1];
    }
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
    assert (issame(derivative({3, 1, 2, 4, 5}) , {1, 4, 12, 20}));
    assert (issame(derivative({1, 2, 3}) , {2, 6}));
    assert (issame(derivative({3, 2, 1}) , {2, 2}));
    assert (issame(derivative({3, 2, 1, 0, 4}) , {2, 2, 0, 16}));
    assert (issame(derivative({1}) , {}));
}
