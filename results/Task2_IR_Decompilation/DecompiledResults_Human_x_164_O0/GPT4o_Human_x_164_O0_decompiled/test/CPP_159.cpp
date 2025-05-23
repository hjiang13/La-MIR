#include <vector>
#include <initializer_list>
#include <stdexcept>

class MyVector {
public:
    MyVector(int size1, int size2, int size3) {
        if (size1 > size3) {
            int *data = new int[2];
            data[0] = size1 + size2;
            data[1] = 0;
            std::initializer_list<int> initList(data, 2);
            vec = std::vector<int>(initList);
            delete[] data;
        } else {
            int *data = new int[2];
            data[0] = size2;
            data[1] = size3 - size2;
            std::initializer_list<int> initList(data, 2);
            vec = std::vector<int>(initList);
            delete[] data;
        }
    }

    ~MyVector() = default;

private:
    std::vector<int> vec;
};

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
