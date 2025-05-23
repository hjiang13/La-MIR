/*
Given length of a side and high return area for a triangle.
>>> triangle_area(5, 3)
7.5
*/
#include<stdio.h>
#include<math.h>
using namespace std;
float triangle_area(float a,float h){

return (a*h)*0.5;

}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(triangle_area(5, 3) - 7.5)<1e-4);
    assert (abs(triangle_area(2, 2) - 2.0)<1e-4);
    assert (abs(triangle_area(10, 8) - 40.0)<1e-4);
}
