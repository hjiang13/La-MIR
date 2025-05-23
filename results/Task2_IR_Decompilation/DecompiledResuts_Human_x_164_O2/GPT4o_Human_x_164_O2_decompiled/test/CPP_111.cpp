#include <map>
#include <string>
#include <tuple>
#include <utility>

void histogram(std::map<char, int>& m, const std::string& s) {
    using namespace std;
    tuple<char, int> t;
    char c;
    size_t i = 0;

    while (i < s.size()) {
        c = s[i];
        auto it = m.find(c);
        if (it != m.end()) {
            it->second++;
        } else {
            m.insert(make_pair(c, 1));
        }
        i++;
    }
}

#undef NDEBUG
#include<assert.h>
bool issame(map<char,int> a,map<char,int> b){
    if (a.size()!=b.size()) return false;
    map <char,int>::iterator it;
    for (it=a.begin();it!=a.end();it++)
    {
        char w1=it->first;
        int w2=it->second;
        if (b.find(w1)==b.end()) return false;
        if (b[w1]!=w2) return false;
    }

    return true;
}
int main(){
    assert (issame(histogram("a b b a") , {{'a',2},{'b', 2}}));
    assert (issame(histogram("a b c a b") , {{'a', 2},{'b', 2}}));
    assert (issame(histogram("a b c d g") , {{'a', 1}, {'b', 1}, {'c', 1}, {'d', 1}, {'g', 1}}));
    assert (issame(histogram("r t g") , {{'r', 1},{'t', 1},{'g', 1}}));
    assert (issame(histogram("b b b b a") , {{'b', 4}}));
    assert (issame(histogram("r t g") , {{'r', 1},{'t', 1},{'g', 1}}));
    assert (issame(histogram("") , {}));
    assert (issame(histogram("a") , {{'a', 1}}));
}
