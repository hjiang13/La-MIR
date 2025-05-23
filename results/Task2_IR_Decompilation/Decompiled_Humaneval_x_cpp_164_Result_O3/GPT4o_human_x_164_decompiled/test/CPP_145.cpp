#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cstring>

void order_by_points(std::vector<int> &vec1, std::vector<int> &vec2) {
    std::string str;
    int *ptr1 = vec1.data();
    int *ptr2 = vec2.data();
    
    if (ptr1 == ptr2) return;

    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    for (size_t i = 0; i < size1; ++i) {
        for (size_t j = 0; j < size2; ++j) {
            if (ptr1[i] > ptr2[j]) {
                std::swap(ptr1[i], ptr2[j]);
            }
        }
    }

    // Placeholder for the string representation of a formatted output
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", std::abs(ptr1[0]));
    str.assign(buffer);
    std::cout << str << std::endl;
}

int main() {
    std::vector<int> vec1 = {3, 1, 2};
    std::vector<int> vec2 = {6, 5, 4};
    order_by_points(vec1, vec2);
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
    assert (issame(order_by_points({1, 11, -1, -11, -12}) , {-1, -11, 1, -12, 11}));
    assert (issame(order_by_points({1234,423,463,145,2,423,423,53,6,37,3457,3,56,0,46}) , {0, 2, 3, 6, 53, 423, 423, 423, 1234, 145, 37, 46, 56, 463, 3457}));
    assert (issame(order_by_points({}) , {}));
    assert (issame(order_by_points({1, -11, -32, 43, 54, -98, 2, -3}) , {-3, -32, -98, -11, 1, 2, 43, 54}));
    assert (issame(order_by_points({1,2,3,4,5,6,7,8,9,10,11}) , {1, 10, 2, 11, 3, 4, 5, 6, 7, 8, 9}));
    assert (issame(order_by_points({0,6,6,-76,-21,23,4}) , {-76, -21, 0, 4, 23, 6, 6}));
    
}
