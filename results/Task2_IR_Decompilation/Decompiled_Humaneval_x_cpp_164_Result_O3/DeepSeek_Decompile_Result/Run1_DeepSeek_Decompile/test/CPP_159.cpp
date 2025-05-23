#include <vector>
#include <cstring>
#include <new> // for std::nothrow

using namespace std;

void eat(vector<int>* v, int a, int b, int c) {
    // Check if c is less than b
    if (c < b) {
        // Calculate sum of a and c
        int sum = a + c;
        
        // Allocate memory for vector data
        int* data = new (nothrow) int[8];
        if (data == nullptr) {
            // Handle memory allocation failure if needed
            return;
        }
        
        // Initialize memory to zero
        memset(data, 0, sizeof(int) * 8);
        
        // Set up vector's pointers and data
        v->_M_impl._M_start = data;
        v->_M_impl._M_end_of_storage = data + 8;
        v->_M_impl._M_end = data + 4;
        
        // Store the sum
        *data = sum;
    } else {
        // Calculate difference between c and b, and sum of b and a
        int diff = c - b;
        int sum = b + a;
        
        // Allocate memory for vector data
        int* data = new (nothrow) int[8];
        if (data == nullptr) {
            // Handle memory allocation failure if needed
            return;
        }
        
        // Initialize memory to zero
        memset(data, 0, sizeof(int) * 8);
        
        // Set up vector's pointers and data
        v->_M_impl._M_start = data;
        v->_M_impl._M_end_of_storage = data + 8;
        v->_M_impl._M_end = data + 4;
        
        // Store the sum
        *(data + 1) = sum;
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
    assert (issame(eat(5, 6, 10) , {11, 4}));
    assert (issame(eat(4, 8, 9) , {12, 1}));
    assert (issame(eat(1, 10, 10) , {11, 0}));
    assert (issame(eat(2, 11, 5) , {7, 0}));
    
    assert (issame(eat(4, 5, 7) , {9, 2}));
    assert (issame(eat(4, 5, 1) , {5, 0}));
}
