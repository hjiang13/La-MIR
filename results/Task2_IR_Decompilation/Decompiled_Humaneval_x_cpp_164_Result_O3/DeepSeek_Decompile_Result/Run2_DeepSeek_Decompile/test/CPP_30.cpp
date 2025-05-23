#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<float> get_positive(const vector<float>& vec) {
    vector<float> result;
    if (vec.empty()) {
        return result;
    }

    const float* begin = &vec[0];
    const float* end = begin + vec.size();
    const float* current = begin;

    while (current != end) {
        if (*current > 0.0f) {
            result.push_back(*current);
        }
        current++;
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
    assert (issame(get_positive({-1, -2, 4, 5, 6}) , {4, 5, 6} ));
    assert (issame(get_positive({5, 3, -5, 2, 3, 3, 9, 0, 123, 1, -10}) , {5, 3, 2, 3, 3, 9, 123, 1}));
     assert (issame(get_positive({-1, -2}) , {} ));
     assert (issame(get_positive({}) , {}));
}
