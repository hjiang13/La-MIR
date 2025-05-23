```c++
#include <vector>

int add(std::vector<int> *vec) {
    int result = 0;
    int index = 0;
    
    while (index * 2 + 1 < vec->size()) {
        int element = (*vec)[index * 2 + 1];
        
        if (element % 2 == 0) {
            result += element;
        }
        
        index++;
    }
    
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add({4, 88}) == 88);
    assert (add({4, 5, 6, 7, 2, 122}) == 122);
    assert (add({4, 0, 6, 7}) == 0);
    assert (add({4, 4, 6, 8}) == 12);
}
