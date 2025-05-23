#include <vector>
#include <stdexcept>

using namespace std;

void generate_integers(vector<int>& result, int start, int end) {
    bool ascending = (start < end);
    int step = ascending ? 1 : -1;
    int current = start;

    while (true) {
        if (current >= 10 && !ascending || current <= 10 && ascending)
            break;

        if (current % 2 == 0) {
            result.push_back(current);
        }

        current += step;
    }

    // Ensure the vector has sufficient capacity
    size_t required_capacity = result.size();
    if (required_capacity > result.capacity()) {
        size_t new_capacity = max<size_t>(required_capacity, result.capacity() * 2);
        result.reserve(new_capacity);
    }
}

int main() {
    vector<int> numbers;
    generate_integers(numbers, 0, 20);
    return 0;
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
