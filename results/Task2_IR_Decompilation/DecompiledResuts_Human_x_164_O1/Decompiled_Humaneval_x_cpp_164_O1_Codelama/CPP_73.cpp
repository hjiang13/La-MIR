```

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


```

Note: The decompiled code may not be exactly the same as the original source code, but it should be functionally equivalent.