
        #include<stdio.h>
#include<string>
using namespace std;
int smallest_change(vector<int> numbers){

    int min_change=INT_MAX;
    for (int i=0;i<numbers.size();i++)
    {
        int change=0;
        for (int j=i+1;j<numbers.size();j++)
        {
            if (numbers[j]<numbers[i]) change+=1;
        }
        if (change<min_change) min_change=change;
    }
    return min_change;
}



#undef NDEBUG
#include<assert.h>
int main(){
    assert (smallest_change({1,2,3,5,4,7,9,6}) == 4);
    assert (smallest_change({1, 2, 3, 4, 3, 2, 2}) == 1);
    assert (smallest_change({1, 4, 2}) == 1);
    assert (smallest_change({1, 4, 4, 2}) == 1);
    assert (smallest_change({1, 2, 3, 2, 1}) == 0);
    assert (smallest_change({3, 1, 1, 3}) == 0);
    assert (smallest_change({1}) == 0);
    assert (smallest_change({0, 1}) == 1);
}
