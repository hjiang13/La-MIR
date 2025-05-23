#include <vector>

void fi(std::vector<int>& vec, int val) {
    int size = 0;
    int capacity = 1;
    int index = 0;
    bool exceptionThrown = false;
    
    vec.clear();
    
    while (true) {
        if (size <= capacity) {
            if (index % 2 == 0) {
                vec.push_back(val);
            } else {
                vec.push_back(size);
            }
            size++;
            index++;
        } else {
            exceptionThrown = true;
            break;
        }
    }
    
    if (exceptionThrown) {
        vec.~vector();
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
    assert (issame(f(5) , {1, 2, 6, 24, 15}));
    assert (issame(f(7) , {1, 2, 6, 24, 15, 720, 28}));
    assert (issame(f(1) , {1}));
    assert (issame(f(3) , {1, 2, 6}));
}
