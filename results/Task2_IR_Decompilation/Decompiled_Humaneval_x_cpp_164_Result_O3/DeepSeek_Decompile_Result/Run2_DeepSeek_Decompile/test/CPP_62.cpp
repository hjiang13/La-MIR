#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<float> derivative(const vector<float>& input) {
    vector<float> result;
    float* input_data = input.data();
    size_t size = input.size();

    if (size == 0) {
        return result;
    }

    result.reserve(size);
    result.resize(size, 0.0f);

    if (size == 1) {
        result[0] = 0.0f;
        return result;
    }

    for (size_t i = 0; i < size; ++i) {
        if (i == 0) {
            result[i] = input_data[1] - input_data[0];
        } else if (i == size - 1) {
            result[i] = input_data[size - 1] - input_data[size - 2];
        } else {
            result[i] = (input_data[i + 1] - input_data[i - 1]) / 2.0f;
        }
    }

    return result;
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
