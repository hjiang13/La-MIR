```cpp
#include <vector>

void generate_integers(std::vector<int>& vec, int start, int end) {
    if (end < start) {
        int temp = start;
        start = end;
        end = temp;
    }

    std::memset(reinterpret_cast<void*>(&vec), 0, sizeof(vec));

    int* start_ptr = &vec[0];
    int* end_ptr = &vec[0] + 1;

    for (int i = start; i < end; ++i) {
        if (i < 10 && i % 2 == 0) {
            if (start_ptr == end_ptr) {
                *start_ptr = i;
            } else {
                *start_ptr = i;
                start_ptr++;
            }
        } else {
            vec.insert(start_ptr, i);
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
    assert (issame(generate_integers(2, 10) , {2, 4, 6, 8}));
    assert (issame(generate_integers(10, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(132, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(17,89) , {}));
}
