#include <vector>
#include <cstring>
#include <new>

void generate_integers(std::vector<int>& vec, int start, int end) {
    bool reverse = start > end;
    int current = reverse ? end : start;
    int limit = reverse ? start : end;

    vec = std::vector<int>(); // Initialize vector

    while (current <= limit) {
        if (current < 10 && (current % 2) == 0) {
            // Store directly if condition is met
            vec.push_back(current);
        } else {
            // Reallocate if needed
            size_t size = vec.size();
            size_t new_capacity = size > 0 ? 2 * size : 1;

            int* new_data = static_cast<int*>(operator new(new_capacity * sizeof(int)));
            std::memmove(new_data, vec.data(), size * sizeof(int));
            vec.assign(new_data, new_data + size);
            vec.reserve(new_capacity);

            vec.push_back(current);
        }
        current++;
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
