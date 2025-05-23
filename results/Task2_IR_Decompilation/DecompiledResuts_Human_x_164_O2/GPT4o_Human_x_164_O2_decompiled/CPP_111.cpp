```cpp
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
```