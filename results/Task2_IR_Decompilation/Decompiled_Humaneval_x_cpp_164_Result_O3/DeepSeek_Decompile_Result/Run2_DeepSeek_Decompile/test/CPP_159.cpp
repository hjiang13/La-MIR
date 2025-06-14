#include <vector>
using namespace std;

void eat(vector<int>* v, int a, int b, int c) {
    if (c < b) {
        int size = a + c;
        v->__impl_data.__data_ = new int[size];
        v->__impl_data.__size = size;
        v->__impl_data.__cap = size;
    } else {
        int size = b - c;
        v->__impl_data.__data_ = new int[size];
        v->__impl_data.__size = size;
        v->__impl_data.__cap = size;
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
