#include <vector>
#include <string>
#include <iostream>

void bf(std::vector<std::string>& vec, const std::string& str1, const std::string& str2) {
    vec.reserve(8);
    vec.push_back("Mercury");
    vec.push_back("Venus");
    vec.push_back("Earth");
    vec.push_back("Jupiter");
    vec.push_back("Saturn");
    vec.push_back("Uranus");
    vec.push_back("Neptune");
}

int main() {
    std::vector<std::string> planets;
    bf(planets, "Earth", "Mars");

    for (const auto& planet : planets) {
        std::cout << planet << std::endl;
    }

    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(bf("Jupiter", "Neptune") , {"Saturn", "Uranus"}));
    assert (issame(bf("Earth", "Mercury") , {"Venus",}));
    assert (issame(bf("Mercury", "Uranus") , {"Venus", "Earth", "Mars", "Jupiter", "Saturn"}));
    assert (issame(bf("Neptune", "Venus") , {"Earth", "Mars", "Jupiter", "Saturn", "Uranus"}));
    assert (issame(bf("Earth", "Earth") , {}));
    assert (issame(bf("Mars", "Earth") , {}));
    assert (issame(bf("Jupiter", "Makemake") , {}));
}
