#include <vector>
#include <algorithm> // for std::abs
#include <cstring>   // for std::memset
#include <exception> // for std::length_error

using namespace std;

void compare(vector<int>* c, const vector<int>& a, const vector<int>& b) {
    // Initialize the memory for vector c
    memset(c, 0, sizeof(vector<int>));

    vector<int>::iterator i = a.begin();
    vector<int>::iterator j = b.begin();

    while (i != a.end() || j != b.end()) {
        if (i != a.end() && j != b.end()) {
            if (*i < *j) {
                c->push_back(*i);
                ++i;
            } else {
                c->push_back(*j);
                ++j;
            }
        } else if (i != a.end()) {
            c->insert(c->end(), i, a.end());
            break;
        } else {
            c->insert(c->end(), j, b.end());
            break;
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
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,5,0,0,0,4},{4,1,1,0,0,-2}),{4,4,1,0,0,6}));
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,0,0,0,0,0},{0,0,0,0,0,0}),{0,0,0,0,0,0}));
    assert (issame(compare({1,2,3},{-1,-2,-3}),{2,4,6}));
    assert (issame(compare({1,2,3,5},{-1,2,3,4}),{2,0,0,1}));
}
