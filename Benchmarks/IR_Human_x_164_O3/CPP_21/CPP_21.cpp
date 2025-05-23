/*
Given vector of numbers (of at least two elements), apply a linear transform to that vector,
such that the smallest number will become 0 and the largest will become 1
>>> rescale_to_unit({1.0, 2.0, 3.0, 4.0, 5.0})
{0.0, 0.25, 0.5, 0.75, 1.0}
*/
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
vector<float> rescale_to_unit(vector<float> numbers){ 

    float min=100000,max=-100000;
    for (int i=0;i<numbers.size();i++)
        {
            if (numbers[i]<min) min=numbers[i];
            if (numbers[i]>max) max=numbers[i];
        }
    for (int i=0;i<numbers.size();i++)
        numbers[i]=(numbers[i]-min)/(max-min);
    return numbers;
}
