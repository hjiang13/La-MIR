#include <vector>
#include <cstring>

using namespace std;

void pluck(vector<int>* vecResult, const vector<int>& vecSource) {
    // Initialize memory for vecResult
    memset(vecResult, 0, sizeof(vector<int>));

    int* pData = NULL;
    int* pStart = vecSource.data();
    int* pEnd = pStart + vecSource.size();
    
    while (pData = const_cast<int*>(pStart)) {
        if ((*pData & 1) == 0) { // Check if the number is even
            // Allocate memory and copy data
            int* newData = new int;
            memcpy(newData, pData, sizeof(int));
            vecResult->push_back(*newData);
            delete[] newData;
        }
        pStart++;
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
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}
