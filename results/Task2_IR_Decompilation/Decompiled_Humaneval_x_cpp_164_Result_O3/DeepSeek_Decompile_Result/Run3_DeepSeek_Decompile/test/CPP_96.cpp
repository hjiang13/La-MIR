#include <vector>
#include <cstring>
#include <stdexcept>

using namespace std;

void count_up_to(vector<int>* this, int count) {
    if (count > 2) {
        // Initialize the vector's internal pointers
        int* ptr_begin = nullptr;
        int* ptr_end = nullptr;
        int* ptr_capacity = nullptr;
        
        // Loop through numbers starting from 2
        int current = 2;
        while (current <= count) {
            // Check if reallocation is needed
            if (ptr_begin == ptr_capacity) {
                // Calculate new capacity
                size_t new_capacity = max(static_cast<size_t>(current), 2305843009213693951UL);
                int* new_data = static_cast<int*>(operator new(new_capacity * sizeof(int)));
                
                // Copy existing data if any
                if (ptr_begin != nullptr) {
                    memcpy(new_data, ptr_begin, static_cast<size_t>(ptr_capacity - ptr_begin) * sizeof(int));
                    delete[] ptr_begin;
                }
                
                // Update pointers
                ptr_begin = new_data;
                ptr_capacity = ptr_begin + new_capacity;
            }
            
            // Assign current value to the next position
            *(ptr_begin + (current - 2)) = current;
            
            // Check if the square of current exceeds count
            if (current * current > count) {
                break;
            }
            
            current++;
        }
        
        // Set the end pointer based on the last assigned position
        ptr_end = ptr_begin + (current - 2);
        
        // Update the vector's internal pointers
        this->_M_impl._M_start = ptr_begin;
        this->_M_impl._M_finish = ptr_end;
        this->_M_impl._M_end_of_storage = ptr_capacity;
    } else {
        // If count is less than or equal to 2, initialize with 0s
        memset(static_cast<void*>(this), 0, sizeof(vector<int>));
    }
}

// Exception handling functions referenced in the IR
void* operator new(size_t size) {
    return malloc(size);
}

void operator delete(void* ptr) {
    free(ptr);
}

void __throw_length_error(const char* msg) {
    throw length_error(msg);
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
