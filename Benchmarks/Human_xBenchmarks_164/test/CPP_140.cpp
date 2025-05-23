/*
Given a string text, replace all spaces in it with underscores, 
and if a string has more than 2 consecutive spaces, 
then replace all consecutive spaces with - 

fix_spaces("Example") == "Example"
fix_spaces("Example 1") == "Example_1"
fix_spaces(" Example 2") == "_Example_2"
fix_spaces(" Example   3") == "_Example-3"
*/
#include<stdio.h>
#include<string>
using namespace std;
string fix_spaces(string text){

    string out="";
    int spacelen=0;
    for (int i=0;i<text.length();i++)
    if (text[i]==' ') spacelen+=1;
    else
    {
        if (spacelen==1) out=out+'_';
        if (spacelen==2) out=out+"__";
        if (spacelen>2) out=out+'-';
        spacelen=0;
        out=out+text[i];
    }
    if (spacelen==1) out=out+'_';
    if (spacelen==2) out=out+"__";
    if (spacelen>2) out=out+'-';
    return out;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fix_spaces("Example") == "Example");
    assert (fix_spaces("Mudasir Hanif ") == "Mudasir_Hanif_");
    assert (fix_spaces("Yellow Yellow  Dirty  Fellow") == "Yellow_Yellow__Dirty__Fellow");
    assert (fix_spaces("Exa   mple") == "Exa-mple");
    assert (fix_spaces("   Exa 1 2 2 mple") == "-Exa_1_2_2_mple");
}
