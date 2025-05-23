/*
For a given vector of input numbers, calculate Mean Absolute Deviation
around the mean of this dataset.
Mean Absolute Deviation is the average absolute difference between each
element and a centerpoint (mean in this case):
MAD = average | x - x_mean |
>>> mean_absolute_deviation({1.0, 2.0, 3.0, 4.0})
1.0
*/
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
float mean_absolute_deviation(vector<float> numbers){

    float sum=0;
    float avg,msum,mavg;
    int i=0;
    for (i=0;i<numbers.size();i++)
        sum+=numbers[i];
    avg=sum/numbers.size();
    msum=0;
    for (i=0;i<numbers.size();i++)
        msum+=abs(numbers[i]-avg);
    return msum/numbers.size();
}
