#include <vector>
#include <cstring> // For memcpy and memset
#include <new>     // For operator new and delete

using namespace std;

void pluck(vector<int, allocator<int>>* output, const vector<int, allocator<int>>* input) {
    // Initialize the output vector's memory
    memset(output, 0, sizeof(vector<int, allocator<int>>));
    
    if (input->begin() == input->end()) {
        return;
    }

    int* input_start = &*input->begin();
    int* input_end = &*input->end();
    int* current_element = input_start;

    while (true) {
        // Determine if the current element is even or odd
        if ((*current_element) & 1) {
            // If odd, proceed without processing
            current_element++;
            continue;
        }

        // Calculate the offset for memory operations
        ptrdiff_t offset = current_element - input_start;

        // Allocate memory for the new element
        int* new_element = static_cast<int*>(operator new(8));
        *reinterpret_cast<long long*>(new_element) = *reinterpret_cast<long long>(current_element);

        // Update the output vector's pointers
        output->push_back(*current_element);
        
        current_element++;
        
        if (current_element >= input_end) {
            break;
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
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}
