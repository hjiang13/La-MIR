#include <vector>
#include <stdexcept>

using namespace std;

void make_a_pile_i(vector<int>& v, int size) {
    // Initialize the vector's internal pointers and allocate memory
    v._M_realloc_insert(v.begin(), size);

    if (size > 1) {
        // The loop initializes the vector with values starting from 1
        int* data = v._M_data();
        data[0] = 1;
        for (int i = 1; i < size; ++i) {
            data[i] = data[i-1] + 2;
        }
    }
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
    assert (issame(make_a_pile(3) , {3, 5, 7}));
    assert (issame(make_a_pile(4) , {4,6,8,10}));
    assert (issame(make_a_pile(5) , {5, 7, 9, 11, 13}));
    assert (issame(make_a_pile(6) , {6, 8, 10, 12, 14, 16}));
    assert (issame(make_a_pile(8) , {8, 10, 12, 14, 16, 18, 20, 22}));
}
