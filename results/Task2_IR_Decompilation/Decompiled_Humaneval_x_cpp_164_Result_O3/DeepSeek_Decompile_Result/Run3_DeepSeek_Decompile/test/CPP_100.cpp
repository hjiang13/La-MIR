#include <vector>
#include <stdexcept>

using namespace std;

void make_a_pile(int n, vector<int>& result) {
    result.reserve(4);  // Initial capacity

    int* data_ptr = new int(1);
    result._M_impl._M_data()._M_p = data_ptr;
    result._M_impl._M_data()._M_right = data_ptr;
    result._M_impl._M_data()._M_left = data_ptr;

    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            int* current = data_ptr + (i - 1);
            int* previous = data_ptr + (i - 2);
            int* first = data_ptr;

            int elements_between = (current - first) / 2;
            int remaining = (elements_between - 1);

            int value = previous[0] + 2;

            if (current == first) {
                throw length_error("vector::_M_realloc_insert");
            }

            if (current == first + 1) {
                int new_capacity = 1;
                if (new_capacity < 1) {
                    new_capacity = 1;
                }

                int* new_data = new int[new_capacity * 2];
                new_data[remaining] = value;
                memcpy(new_data, data_ptr, (current - first) * sizeof(int));

                delete[] data_ptr;
                data_ptr = new_data;

                result._M_impl._M_data()._M_p = data_ptr + remaining;
                result._M_impl._M_data()._M_right = data_ptr + new_capacity;
                result._M_impl._M_data()._M_left = data_ptr;
            }
        } else {
            *data_ptr = 1;
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
