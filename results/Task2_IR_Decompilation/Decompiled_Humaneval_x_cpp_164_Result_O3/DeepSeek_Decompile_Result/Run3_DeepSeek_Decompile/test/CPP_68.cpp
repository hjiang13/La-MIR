#include <vector>
using namespace std;

void pluck(vector<int>& output, const vector<int>& input) {
    int* data_ptr = nullptr;
    size_t capacity = 0;
    size_t size = 0;

    // Initialize the output vector's internal pointers to nullptr
    memset(&data_ptr, 0, sizeof(data_ptr));
    
    // Get pointers to input vector's data, size, and capacity
    int* input_data = input.data();
    size_t input_size = input.size();
    size_t input_capacity = input.capacity();

    if (input_data == input.data()) {
        return;
    }

    for (size_t i = 0; i < input_size; ++i) {
        int element = input_data[i];
        bool is_even = (element & 1) == 0;

        if (!is_even) {
            // Handle element insertion into output
            if (capacity <= size) {
                // Resize the output vector if necessary
                if (capacity == 0) {
                    capacity = 1;
                    output.resize(capacity);
                } else {
                    int new_capacity = capacity * 2;
                    int* new_data = new int[new_capacity];
                    memcpy(new_data, data_ptr, size * sizeof(int));
                    delete[] data_ptr;
                    data_ptr = new_data;
                    capacity = new_capacity;
                }
            }

            // Insert the element into the output vector
            if (data_ptr != input_data + i) {
                memmove(data_ptr + size, data_ptr, (size * sizeof(int)));
            }
            data_ptr[size++] = element;
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
