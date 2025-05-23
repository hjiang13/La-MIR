#include <vector>
#include <new>
#include <cstdlib>

extern "C" void __gxx_personality_v0();

void eati(std::vector<int>& vec, int a, int b, int c) {
    if (c < b) {
        void* ptr = operator new(8);
        if (ptr) {
            int idx = c + a;
            int* data = reinterpret_cast<int*>(ptr);
            vec.push_back(idx);
            *(reinterpret_cast<int*>(ptr) + 1) = 0; // Placeholder for second element
            *(reinterpret_cast<int*>(ptr) + 2) = reinterpret_cast<int>(ptr); // Store pointer
        } else {
            // Handle allocation failure
            std::terminate();
        }
    } else {
        void* ptr = operator new(8);
        if (ptr) {
            int idx = b + a;
            int* data = reinterpret_cast<int*>(ptr);
            vec.push_back(idx);
            *(reinterpret_cast<int*>(ptr) + 1) = 0; // Placeholder for second element
            *(reinterpret_cast<int*>(ptr) + 2) = reinterpret_cast<int>(ptr); // Store pointer
        } else {
            // Handle allocation failure
            std::terminate();
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
    assert (issame(eat(5, 6, 10) , {11, 4}));
    assert (issame(eat(4, 8, 9) , {12, 1}));
    assert (issame(eat(1, 10, 10) , {11, 0}));
    assert (issame(eat(2, 11, 5) , {7, 0}));
    
    assert (issame(eat(4, 5, 7) , {9, 2}));
    assert (issame(eat(4, 5, 1) , {5, 0}));
}
