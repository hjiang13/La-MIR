/*
There are eight planets in our solar system: the closerst to the Sun 
is Mercury, the next one is Venus, then Earth, Mars, Jupiter, Saturn, 
Uranus, Neptune.
Write a function that takes two planet names as strings planet1 and planet2. 
The function should return a vector containing all planets whose orbits are 
located between the orbit of planet1 and the orbit of planet2, sorted by 
the proximity to the sun. 
The function should return an empty vector if planet1 or planet2
are not correct planet names. 
Examples
bf("Jupiter", "Neptune") ==> {"Saturn", "Uranus"}
bf("Earth", "Mercury") ==> {"Venus"}
bf("Mercury", "Uranus") ==> {"Venus", "Earth", "Mars", "Jupiter", "Saturn"}
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
vector<string> bf(string planet1,string planet2){

    vector<string> planets={"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};
    int pos1=-1,pos2=-1,m;
    for (m=0;m<planets.size();m++)
    {
    if (planets[m]==planet1) pos1=m;
    if (planets[m]==planet2) pos2=m;
    }
    if (pos1==-1 or pos2==-1) return {};
    if (pos1>pos2) {m=pos1;pos1=pos2;pos2=m;}
    vector<string> out={};
    for (m=pos1+1;m<pos2;m++)
    out.push_back(planets[m]);
    return out;
}
