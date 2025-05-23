#include <vector>
#include <stdexcept>

using namespace std;

void generate_integers(vector<int>& vec, int start, int end) {
    bool increasing = start < end;
    int current = increasing ? start : end;
    int limit = increasing ? end : start;

    vec.clear();

    while (true) {
        if (current > limit)
            break;

        if (vec.capacity() == 0) {
            vec.push_back(current);
        } else {
            size_t new_capacity = vec.capacity() > 0 ? vec.capacity() * 2 : 1;
            if (new_capacity > 0x7FFFFFFFFFFFFFFD) {
                throw length_error("vector::_M_realloc_insert");
            }

            vector<int> temp;
            temp.reserve(new_capacity);
            temp.swap(vec);
            temp.push_back(current);
            vec = temp;
        }

        current += 2;
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
