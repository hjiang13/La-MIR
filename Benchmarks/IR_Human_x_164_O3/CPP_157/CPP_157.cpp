/*
Given the lengths of the three sides of a triangle. Return true if the three
sides form a right-angled triangle, false otherwise.
A right-angled triangle is a triangle in which one angle is right angle or 
90 degree.
Example:
right_angle_triangle(3, 4, 5) == true
right_angle_triangle(1, 2, 3) == false
*/
#include<stdio.h>
#include<math.h>
using namespace std;
bool right_angle_triangle(float a,float b,float c){

    if (abs(a*a+b*b-c*c)<1e-4 or abs(a*a+c*c-b*b)<1e-4 or abs(b*b+c*c-a*a)<1e-4) return true;
    return false;
}
