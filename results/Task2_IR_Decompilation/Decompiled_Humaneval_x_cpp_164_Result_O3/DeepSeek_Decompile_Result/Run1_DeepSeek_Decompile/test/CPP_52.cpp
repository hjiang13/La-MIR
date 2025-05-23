#include <vector>

using namespace std;

bool below_threshold(const vector<int>& v, int threshold) {
    size_t size = v.size();
    
    if (size == 0) {
        return true;
    }
    
    size_t num_elements = max(1U, size / 4);
    
    for (size_t i = 0; i < num_elements; ++i) {
        if (v[i] >= threshold) {
            return false;
        }
    }
    
    return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_threshold({1, 2, 4, 10}, 100));
    assert (not(below_threshold({1, 20, 4, 10}, 5)));
    assert (below_threshold({1, 20, 4, 10}, 21));
    assert (below_threshold({1, 20, 4, 10}, 22));
    assert (below_threshold({1, 8, 4, 10}, 11));
    assert (not(below_threshold({1, 8, 4, 10}, 10)));
}
