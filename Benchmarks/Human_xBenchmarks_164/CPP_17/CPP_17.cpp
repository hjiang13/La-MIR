/*
Input to this function is a string representing musical notes in a special ASCII format.
Your task is to parse this string and return vector of integers corresponding to how many beats does each
not last.

Here is a legend:
"o" - whole note, lasts four beats
"o|" - half note, lasts two beats
".|" - quater note, lasts one beat

>>> parse_music("o o| .| o| o| .| .| .| .| o o")
{4, 2, 1, 2, 2, 1, 1, 1, 1, 4, 4}
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
vector<int> parse_music(string music_string){ 

    string current="";
    vector<int> out={};
    if (music_string.length()>0)
        music_string=music_string+' ';
    for (int i=0;i<music_string.length();i++)
    {
        if (music_string[i]==' ')
        {
            if (current=="o") out.push_back(4);
            if (current=="o|") out.push_back(2);
            if (current==".|") out.push_back(1);
            current="";
        }
        else current+=music_string[i];
    }
    return out;
}
