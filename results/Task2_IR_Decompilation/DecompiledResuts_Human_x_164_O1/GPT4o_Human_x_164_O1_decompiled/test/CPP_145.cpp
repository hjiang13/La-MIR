#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

void order_by_points(std::vector<int>& vec1, std::vector<int>& vec2) {
    std::vector<int> temp_vec;
    std::string str;
    int count = 0;
    
    int* start1 = vec1.data();
    int* end1 = start1 + vec1.size();
    int* start2 = vec2.data();
    
    if (end1 == start1) return; // if vec1 is empty
    
    for (int* it = start1; it < end1; ++it) {
        if (*it > 0) {
            temp_vec.push_back(*it);
            count++;
        }
    }
    
    if (count > 0) {
        int abs_count = abs(count);
        str.resize(16);
        int written = snprintf(&str[0], str.size(), "%d", abs_count);
        
        if (written >= 0) {
            for (int i = 0; i < count; i++) {
                vec2.push_back(temp_vec[i]);
            }
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
    assert (issame(order_by_points({1, 11, -1, -11, -12}) , {-1, -11, 1, -12, 11}));
    assert (issame(order_by_points({1234,423,463,145,2,423,423,53,6,37,3457,3,56,0,46}) , {0, 2, 3, 6, 53, 423, 423, 423, 1234, 145, 37, 46, 56, 463, 3457}));
    assert (issame(order_by_points({}) , {}));
    assert (issame(order_by_points({1, -11, -32, 43, 54, -98, 2, -3}) , {-3, -32, -98, -11, 1, 2, 43, 54}));
    assert (issame(order_by_points({1,2,3,4,5,6,7,8,9,10,11}) , {1, 10, 2, 11, 3, 4, 5, 6, 7, 8, 9}));
    assert (issame(order_by_points({0,6,6,-76,-21,23,4}) , {-76, -21, 0, 4, 23, 6, 6}));
    
}
