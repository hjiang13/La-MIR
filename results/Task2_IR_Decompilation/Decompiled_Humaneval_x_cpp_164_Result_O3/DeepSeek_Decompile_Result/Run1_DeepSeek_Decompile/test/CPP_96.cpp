#include <vector>
#include <stdexcept>
#include <cstring>  // For memset

using namespace std;

vector<int> count_up_to(int n) {
    vector<int> result;
    if (n <= 2) {
        return result;
    }

    // Initialize the vector
    int* start_ptr = result._Get_first();
    int* end_ptr = result._Get_last();
    int* cap_ptr = result._Get_end();

    // Allocate initial memory
    memset(&result, 0, sizeof(result));

    int i = 2;
    while (true) {
        int square = i * i;
        if (square > n) {
            break;
        }

        // Check if we need to reallocate
        if (end_ptr >= cap_ptr) {
            size_t current_size = end_ptr - start_ptr;
            size_t new_size = max(static_cast<size_t>(2), current_size * 2);
            int* new_start = new (nothrow) int[new_size];
            if (!new_start) {
                throw bad_alloc();
            }
            memmove(new_start, start_ptr, current_size * sizeof(int));
            delete[] start_ptr;
            start_ptr = new_start;
            end_ptr = start_ptr + current_size;
            cap_ptr = start_ptr + new_size;
        }

        *end_ptr = i;
        end_ptr++;
        i++;
    }

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
    assert (issame(count_up_to(5) , {2,3}));
    assert (issame(count_up_to(6) , {2,3,5}));
    assert (issame(count_up_to(7) , {2,3,5}));
    assert (issame(count_up_to(10) , {2,3,5,7}));
    assert (issame(count_up_to(0) , {}));
    assert (issame(count_up_to(22) , {2,3,5,7,11,13,17,19}));
    assert (issame(count_up_to(1) , {}));
    assert (issame(count_up_to(18) , {2,3,5,7,11,13,17}));
    assert (issame(count_up_to(47) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}));
    assert (issame(count_up_to(101) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}));
}
